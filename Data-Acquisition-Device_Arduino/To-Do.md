% To-Do.md
% David Rihtaršič

Function PcFrequency() As Short
Function PcCounter() As Short
Function PcTime() As Double
Function PcWait(SecondsToWait As Double) As Double

'------------Osnovne funkcije za R/W registre----------------------
#Function ProcessReset() As String
#Function ReadRegister(Register As RegName) As Byte
#Function SetRegister(ByVal RegisterName As RegName, ByVal RegisterValue As Byte) As Integer
#Function SetRegisterBit(ByVal RegisterName As RegName, ByVal BitNumber As Byte) As Integer
#Function ClearRegisterBit(ByVal RegisterName As RegName, ByVal BitNumber As Byte) As Integer
#Function ReadRegisterBit(ByVal RegisterName As RegName, ByVal BitNumber As Byte) As Byte
#Function WaitUntilBitIsSet(ByVal RegisterName As RegName, ByVal BitNumber As Byte) As Integer
#Function WaitUntilBitIsCleared(ByVal RegisterName As RegName, ByVal BitNumber As Byte) As Integer
Function Read16BitRegister_IncAddr(ByVal RegisterLoName As RegName) As Integer
Function Read16BitRegister_DecAddr(ByVal RegisterHiName As RegName) As Integer

'------------naprednejše funkcije---------------------------------
#Function ReadADC_ch(ByVal Channel As Byte) As Integer
#Function ReadADC() As Integer
#Function GetCmdBufferNumber() As Integer
#Function Cmd_Do() As Integer
#Function Cmd_Loop() As Integer

'------------časovne funkcije za Timer1--------------------------
Function SetTimer1AsDelay(ByVal delayInMicroSeconds As Integer) As Integer
Function DelayTimer1() As Integer
Function GetFclk() As Integer
Function CalibrateFclk(ByVal Freq_calibration As Integer) As Integer

'------------testing ... ---------------------------------------
Function SetTimer1AsStopWatch(ByVal Prescaller As Integer) As Integer
Function StartStopWatchTimer1() As Integer
Function StopStopWatchTimer1() As Integer
Function ReadStopWatchTimer1() As Integer
Function ResetStopWatchTimer1() As Integer

 
    Public Function Read16BitRegister_IncAddr(ByVal RegisterLoName As RegName) As Integer Implements ComDuino.Read16BitRegister_IncAddr
        Dim SendBuffer As Byte() = {CMD.Read_16_bit_register_incr_addr, RegisterLoName}
        Comm.DiscardInBuffer()
        Read16BitRegister_IncAddr = -1
        Try
            SerialWriteBuffer(SendBuffer, 0, 2)

            SendBuffer(0) = Comm.ReadByte()
            SendBuffer(1) = Comm.ReadByte()
            Read16BitRegister_IncAddr = 256 * SendBuffer(1) + SendBuffer(0)
        Catch ex As Exception
            'MsgBox(ex.Message)'
            Return ex.HResult
        End Try
    End Function
    Public Function Read16BitRegister_DecAddr(ByVal RegisterHiName As RegName) As Integer Implements ComDuino.Read16BitRegister_DecAddr
        Dim SendBuffer As Byte() = {CMD.Read_16_bit_register_decr_addr, RegisterHiName}
        Read16BitRegister_DecAddr = -1
        Comm.DiscardInBuffer()
        Try
            SerialWriteBuffer(SendBuffer, 0, 2)

            SendBuffer(1) = Comm.ReadByte()
            SendBuffer(0) = Comm.ReadByte()
            Read16BitRegister_DecAddr = 256 * SendBuffer(1) + SendBuffer(0)
        Catch ex As Exception
            'MsgBox(ex.Message)'
            Return ex.HResult
        End Try
    End Function

    '------Časovne finkcije za TIMER1 --------------------------------
    'Public Prescaller As Integer
    Public Timer1PrescallerOptions As Integer() = {0, 1, 8, 64, 256, 1024}
    Public Timer1PrescallerNum As Byte 'TCCR1BVal.=0, 1, 2,  3,   4,   5'
    Public F_clk As Integer = 16000000
    Public F_clk_MHz As Double = F_clk / 1000000
    Public Function GetFclk() As Integer Implements ComDuino.GetFclk
        Try
            Return F_clk
        Catch ex As Exception
            'MsgBox(ex.Message)'
            Return ex.HResult
        End Try
    End Function
    Public Function CalibrateFclk(ByVal Freq_calibration As Integer) As Integer Implements ComDuino.CalibrateFclk
        Try
            Me.F_clk = Freq_calibration
            Me.F_clk_MHz = F_clk / 1000000
            Return 0
        Catch ex As Exception
            'MsgBox(ex.Message)'
            Return ex.HResult
        End Try
    End Function
    Public Function SetTimer1AsDelay(ByVal delayInMicroSeconds As Integer) As Integer Implements ComDuino.SetTimer1AsDelay
        Dim OCR As Integer
        Dim n As Byte
        Try
            Me.SetRegister(RegName.TCCR1A, &H0)
            Me.SetRegister(RegName.TCCR1B, &H0)
            Me.SetRegister(RegName.TCNT1H, &H0)
            Me.SetRegister(RegName.TCNT1L, &H0)
            Me.SetRegister(RegName.OCR1AH, &H0)
            Me.SetRegister(RegName.OCR1AL, &H0)
            For n = 1 To 5
                OCR = ((F_clk / Me.Timer1PrescallerOptions.ElementAt(n)) - 1) * delayInMicroSeconds / 1000000
                'MsgBox("OCR=" & OCR & Chr(10) & "n=" & n)'
                If OCR < 65536 Then Exit For
            Next
            If OCR > &HFFFF Then
                'Error prevelik cas...'
                Return -1
            Else
                'Vse OK ... nadaljuj'
                'SetDelayTimer1 = Int(Prescaller.ElementAt(n) * (1 + OCR) / F_clk_MHz)'
                Dim OCR_bytes As Byte() = BitConverter.GetBytes(OCR)
                ' MsgBox(OCR_bytes(0) & Chr(10) & OCR_bytes(1) & Chr(10) & OCR_bytes(2) & Chr(10) & OCR_bytes(3) & Chr(10))'
                'nastavi Compare Register OCR1A'
                Me.SetRegister(RegName.OCR1AH, OCR_bytes(1))
                Me.SetRegister(RegName.OCR1AL, OCR_bytes(0))
                'Set WGM12 = "8" => Timer1 = CTC'
                'Set PRESCALLER  => Timer1 = Run'
                Me.SetRegister(RegName.TCCR1A, &H0)
                Me.SetRegister(RegName.TCCR1B, 8 + n)
                Return Int(Me.Timer1PrescallerOptions.ElementAt(n) * (1 + OCR) / F_clk_MHz)
            End If
        Catch ex As Exception
            'MsgBox(ex.Message)'
            Return ex.HResult
        End Try
    End Function
    Public Function DelayTimer1() As Integer Implements ComDuino.DelayTimer1
        Try
            'To Do'
            'Najprej poglej, če je timer sploh vključen... potem čakaj'
            'Drugače pa daj opozorilo, da "Timer1 NI VKLJUČEN!!!"'
            Me.WaitUntilBitIsSet(RegName.TIFR1, 1)
            Me.SetRegisterBit(RegName.TIFR1, 1)
            Return 0
        Catch ex As Exception
            'MsgBox(ex.Message)'
            Return ex.HResult
        End Try
    End Function
    Public Function SetTimer1AsStopWatch(ByVal Prescaller As Integer) As Integer Implements ComDuino.SetTimer1AsStopWatch
        Try
            Me.SetRegister(RegName.TCCR1A, &H0)
            Me.SetRegister(RegName.TCCR1B, &H0)
            Me.SetRegister(RegName.TCCR1C, &H0)
            Me.SetRegister(RegName.TCNT1H, &H0) 'Timer1 Value HIGH'
            Me.SetRegister(RegName.TCNT1L, &H0) 'Timer1 Value LOW'
            Me.SetRegister(RegName.OCR1AH, &H0)
            Me.SetRegister(RegName.OCR1AL, &H0)
            Me.SetRegister(RegName.OCR1BH, &H0)
            Me.SetRegister(RegName.OCR1BL, &H0)
            Me.SetRegister(RegName.ICR1H, &H0)
            Me.SetRegister(RegName.ICR1L, &H0)
            Me.SetRegister(RegName.TIMSK1, &H0)
            Me.SetRegister(RegName.TIFR1, &HFF) 'Clear all Int flags'
            For Me.Timer1PrescallerNum = 1 To 5
                If Prescaller = Me.Timer1PrescallerOptions.ElementAt(Me.Timer1PrescallerNum) Then
                    'Nastalivili smo PrescallerNum za timer1'
                    Return 0
                    Exit For
                End If
            Next
            Return -1
        Catch ex As Exception
            'MsgBox(ex.Message)'
            Return ex.HResult
        End Try
    End Function
    Public Function StartStopWatchTimer1() As Integer Implements ComDuino.StartStopWatchTimer1
        Try
            Me.SetRegister(RegName.TCCR1B, Timer1PrescallerNum)
            Return 0
        Catch ex As Exception
            'MsgBox(ex.Message)'
            Return ex.HResult
        End Try
    End Function
    Public Function StopStopWatchTimer1() As Integer Implements ComDuino.StopStopWatchTimer1
        Try
            Me.SetRegister(RegName.TCCR1B, &H0)
            Return 0
        Catch ex As Exception
            'MsgBox(ex.Message)'
            Return ex.HResult
        End Try
    End Function
    Public Function ReadStopWatchTimer1() As Integer Implements ComDuino.ReadStopWatchTimer1
        Try
            ReadStopWatchTimer1 = Me.Read16BitRegister_IncAddr(RegName.TCNT1)
            If Me.ReadRegisterBit(RegName.TIFR1, 0) = 1 Then
                Me.SetRegisterBit(RegName.TIFR1, 0) ' Clear OVF Flag'
                ReadStopWatchTimer1 = (ReadStopWatchTimer1 + &HFFFF) * -1
            End If
            ReadStopWatchTimer1 = Int(ReadStopWatchTimer1 * Me.Timer1PrescallerOptions(Me.Timer1PrescallerNum) / Me.F_clk_MHz)
            Return ReadStopWatchTimer1
        Catch ex As Exception
            'MsgBox(ex.Message)'
            Return ex.HResult
        End Try
    End Function
    Public Function ResetStopWatchTimer1() As Integer Implements ComDuino.ResetStopWatchTimer1
        Try
            Me.SetRegister(RegName.TCNT1H, &H0) 'Timer1 Value HIGH'
            Me.SetRegister(RegName.TCNT1L, &H0) 'Timer1 Value LOW'
            Return 0
        Catch ex As Exception
            'MsgBox(ex.Message)'
            Return ex.HResult
        End Try
    End Function


    '-------Testing --------------------'
    'Public Sub SerialWrite(ByVal WriteText As String) Implements ComDuino.SerialWrite'
    '    SerialWriteBuffer(WriteText)'
    'End Sub'
    Public Sub SerialWriteBuffer(ByRef SendBuffer() As Byte, ByVal BufferOffset As Integer, ByVal CountData As Integer)
        Comm.Write(SendBuffer, BufferOffset, CountData)
        CMDBufferNum = CMDBufferNum + CountData
        If CMDBufferNum > 255 Then CMDBufferNum = CMDBufferNum - 256
    End Sub


End Class

