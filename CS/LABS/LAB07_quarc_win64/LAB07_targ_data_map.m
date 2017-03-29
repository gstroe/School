  function targMap = targDataMap(),

  ;%***********************
  ;% Create Parameter Map *
  ;%***********************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 6;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc paramMap
    ;%
    paramMap.nSections           = nTotSects;
    paramMap.sectIdxOffset       = sectIdxOffset;
      paramMap.sections(nTotSects) = dumSection; %prealloc
    paramMap.nTotData            = -1;
    
    ;%
    ;% Auto data (LAB07_P)
    ;%
      section.nData     = 11;
      section.data(11)  = dumData; %prealloc
      
	  ;% LAB07_P.HILInitialize_analog_output_max
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% LAB07_P.HILInitialize_analog_output_min
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% LAB07_P.HILInitialize_final_analog_outp
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% LAB07_P.Kp_gain
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% LAB07_P.Kd_gain
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
	  ;% LAB07_P.HILInitialize_initial_analog_ou
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 5;
	
	  ;% LAB07_P.HILInitialize_set_other_outputs
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 6;
	
	  ;% LAB07_P.HILInitialize_set_other_outpu_e
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 7;
	
	  ;% LAB07_P.HILInitialize_set_other_outp_e1
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 8;
	
	  ;% LAB07_P.HILInitialize_set_other_outpu_l
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 9;
	
	  ;% LAB07_P.HILInitialize_watchdog_analog_o
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 10;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% LAB07_P.HILInitialize_hardware_clocks
	  section.data(1).logicalSrcIdx = 11;
	  section.data(1).dtTransOffset = 0;
	
	  ;% LAB07_P.HILInitialize_initial_encoder_c
	  section.data(2).logicalSrcIdx = 12;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(2) = section;
      clear section
      
      section.nData     = 5;
      section.data(5)  = dumData; %prealloc
      
	  ;% LAB07_P.HILInitialize_analog_output_cha
	  section.data(1).logicalSrcIdx = 13;
	  section.data(1).dtTransOffset = 0;
	
	  ;% LAB07_P.HILReadEncoder_channels
	  section.data(2).logicalSrcIdx = 14;
	  section.data(2).dtTransOffset = 2;
	
	  ;% LAB07_P.HILWriteAnalog_channels
	  section.data(3).logicalSrcIdx = 15;
	  section.data(3).dtTransOffset = 3;
	
	  ;% LAB07_P.HILInitialize_encoder_channels
	  section.data(4).logicalSrcIdx = 16;
	  section.data(4).dtTransOffset = 4;
	
	  ;% LAB07_P.HILInitialize_quadrature
	  section.data(5).logicalSrcIdx = 17;
	  section.data(5).dtTransOffset = 6;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(3) = section;
      clear section
      
      section.nData     = 33;
      section.data(33)  = dumData; %prealloc
      
	  ;% LAB07_P.HILInitialize_active
	  section.data(1).logicalSrcIdx = 18;
	  section.data(1).dtTransOffset = 0;
	
	  ;% LAB07_P.HILInitialize_set_analog_input_
	  section.data(2).logicalSrcIdx = 19;
	  section.data(2).dtTransOffset = 1;
	
	  ;% LAB07_P.HILInitialize_set_analog_inpu_d
	  section.data(3).logicalSrcIdx = 20;
	  section.data(3).dtTransOffset = 2;
	
	  ;% LAB07_P.HILInitialize_set_analog_output
	  section.data(4).logicalSrcIdx = 21;
	  section.data(4).dtTransOffset = 3;
	
	  ;% LAB07_P.HILInitialize_set_analog_outp_j
	  section.data(5).logicalSrcIdx = 22;
	  section.data(5).dtTransOffset = 4;
	
	  ;% LAB07_P.HILInitialize_set_analog_outp_i
	  section.data(6).logicalSrcIdx = 23;
	  section.data(6).dtTransOffset = 5;
	
	  ;% LAB07_P.HILInitialize_set_analog_outp_k
	  section.data(7).logicalSrcIdx = 24;
	  section.data(7).dtTransOffset = 6;
	
	  ;% LAB07_P.HILInitialize_set_analog_outp_o
	  section.data(8).logicalSrcIdx = 25;
	  section.data(8).dtTransOffset = 7;
	
	  ;% LAB07_P.HILInitialize_set_analog_out_kt
	  section.data(9).logicalSrcIdx = 26;
	  section.data(9).dtTransOffset = 8;
	
	  ;% LAB07_P.HILInitialize_set_analog_outp_p
	  section.data(10).logicalSrcIdx = 27;
	  section.data(10).dtTransOffset = 9;
	
	  ;% LAB07_P.HILInitialize_set_clock_frequen
	  section.data(11).logicalSrcIdx = 28;
	  section.data(11).dtTransOffset = 10;
	
	  ;% LAB07_P.HILInitialize_set_clock_frequ_f
	  section.data(12).logicalSrcIdx = 29;
	  section.data(12).dtTransOffset = 11;
	
	  ;% LAB07_P.HILInitialize_set_clock_params_
	  section.data(13).logicalSrcIdx = 30;
	  section.data(13).dtTransOffset = 12;
	
	  ;% LAB07_P.HILInitialize_set_clock_param_l
	  section.data(14).logicalSrcIdx = 31;
	  section.data(14).dtTransOffset = 13;
	
	  ;% LAB07_P.HILInitialize_set_digital_outpu
	  section.data(15).logicalSrcIdx = 32;
	  section.data(15).dtTransOffset = 14;
	
	  ;% LAB07_P.HILInitialize_set_digital_out_i
	  section.data(16).logicalSrcIdx = 33;
	  section.data(16).dtTransOffset = 15;
	
	  ;% LAB07_P.HILInitialize_set_digital_out_f
	  section.data(17).logicalSrcIdx = 34;
	  section.data(17).dtTransOffset = 16;
	
	  ;% LAB07_P.HILInitialize_set_digital_out_d
	  section.data(18).logicalSrcIdx = 35;
	  section.data(18).dtTransOffset = 17;
	
	  ;% LAB07_P.HILInitialize_set_digital_out_o
	  section.data(19).logicalSrcIdx = 36;
	  section.data(19).dtTransOffset = 18;
	
	  ;% LAB07_P.HILInitialize_set_digital_out_h
	  section.data(20).logicalSrcIdx = 37;
	  section.data(20).dtTransOffset = 19;
	
	  ;% LAB07_P.HILInitialize_set_digital_out_k
	  section.data(21).logicalSrcIdx = 38;
	  section.data(21).dtTransOffset = 20;
	
	  ;% LAB07_P.HILInitialize_set_encoder_count
	  section.data(22).logicalSrcIdx = 39;
	  section.data(22).dtTransOffset = 21;
	
	  ;% LAB07_P.HILInitialize_set_encoder_cou_m
	  section.data(23).logicalSrcIdx = 40;
	  section.data(23).dtTransOffset = 22;
	
	  ;% LAB07_P.HILInitialize_set_encoder_param
	  section.data(24).logicalSrcIdx = 41;
	  section.data(24).dtTransOffset = 23;
	
	  ;% LAB07_P.HILInitialize_set_encoder_par_d
	  section.data(25).logicalSrcIdx = 42;
	  section.data(25).dtTransOffset = 24;
	
	  ;% LAB07_P.HILInitialize_set_other_outp_es
	  section.data(26).logicalSrcIdx = 43;
	  section.data(26).dtTransOffset = 25;
	
	  ;% LAB07_P.HILInitialize_set_pwm_outputs_a
	  section.data(27).logicalSrcIdx = 44;
	  section.data(27).dtTransOffset = 26;
	
	  ;% LAB07_P.HILInitialize_set_pwm_outputs_n
	  section.data(28).logicalSrcIdx = 45;
	  section.data(28).dtTransOffset = 27;
	
	  ;% LAB07_P.HILInitialize_set_pwm_outputs_g
	  section.data(29).logicalSrcIdx = 46;
	  section.data(29).dtTransOffset = 28;
	
	  ;% LAB07_P.HILInitialize_set_pwm_outputs_m
	  section.data(30).logicalSrcIdx = 47;
	  section.data(30).dtTransOffset = 29;
	
	  ;% LAB07_P.HILInitialize_set_pwm_outputs_o
	  section.data(31).logicalSrcIdx = 48;
	  section.data(31).dtTransOffset = 30;
	
	  ;% LAB07_P.HILInitialize_set_pwm_params_at
	  section.data(32).logicalSrcIdx = 49;
	  section.data(32).dtTransOffset = 31;
	
	  ;% LAB07_P.HILInitialize_set_pwm_params__c
	  section.data(33).logicalSrcIdx = 50;
	  section.data(33).dtTransOffset = 32;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(4) = section;
      clear section
      
      section.nData     = 8;
      section.data(8)  = dumData; %prealloc
      
	  ;% LAB07_P.SignalGenerator_Amplitude
	  section.data(1).logicalSrcIdx = 51;
	  section.data(1).dtTransOffset = 0;
	
	  ;% LAB07_P.SignalGenerator_Frequency
	  section.data(2).logicalSrcIdx = 52;
	  section.data(2).dtTransOffset = 1;
	
	  ;% LAB07_P.Gain1_Gain
	  section.data(3).logicalSrcIdx = 53;
	  section.data(3).dtTransOffset = 2;
	
	  ;% LAB07_P.InverseModulus1_Modulus
	  section.data(4).logicalSrcIdx = 54;
	  section.data(4).dtTransOffset = 3;
	
	  ;% LAB07_P.ToRads_Gain
	  section.data(5).logicalSrcIdx = 55;
	  section.data(5).dtTransOffset = 4;
	
	  ;% LAB07_P.TransferFcn_A
	  section.data(6).logicalSrcIdx = 56;
	  section.data(6).dtTransOffset = 5;
	
	  ;% LAB07_P.TransferFcn_C
	  section.data(7).logicalSrcIdx = 57;
	  section.data(7).dtTransOffset = 6;
	
	  ;% LAB07_P.TransferFcn_D
	  section.data(8).logicalSrcIdx = 58;
	  section.data(8).dtTransOffset = 7;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(5) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% LAB07_P.HILReadEncoder_Active
	  section.data(1).logicalSrcIdx = 59;
	  section.data(1).dtTransOffset = 0;
	
	  ;% LAB07_P.HILWriteAnalog_Active
	  section.data(2).logicalSrcIdx = 60;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(6) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (parameter)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    paramMap.nTotData = nTotData;
    


  ;%**************************
  ;% Create Block Output Map *
  ;%**************************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 1;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc sigMap
    ;%
    sigMap.nSections           = nTotSects;
    sigMap.sectIdxOffset       = sectIdxOffset;
      sigMap.sections(nTotSects) = dumSection; %prealloc
    sigMap.nTotData            = -1;
    
    ;%
    ;% Auto data (LAB07_B)
    ;%
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% LAB07_B.Gain1
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% LAB07_B.HILReadEncoder
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% LAB07_B.ToRads
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% LAB07_B.Sum1
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (signal)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    sigMap.nTotData = nTotData;
    


  ;%*******************
  ;% Create DWork Map *
  ;%*******************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 5;
    sectIdxOffset = 1;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc dworkMap
    ;%
    dworkMap.nSections           = nTotSects;
    dworkMap.sectIdxOffset       = sectIdxOffset;
      dworkMap.sections(nTotSects) = dumSection; %prealloc
    dworkMap.nTotData            = -1;
    
    ;%
    ;% Auto data (LAB07_DW)
    ;%
      section.nData     = 6;
      section.data(6)  = dumData; %prealloc
      
	  ;% LAB07_DW.HILInitialize_AOMinimums
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% LAB07_DW.HILInitialize_AOMaximums
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 2;
	
	  ;% LAB07_DW.HILInitialize_AOVoltages
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 4;
	
	  ;% LAB07_DW.HILInitialize_FilterFrequency
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 6;
	
	  ;% LAB07_DW.InverseModulus1_PreviousInput
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 8;
	
	  ;% LAB07_DW.InverseModulus1_Revolutions
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 9;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% LAB07_DW.HILInitialize_Card
	  section.data(1).logicalSrcIdx = 6;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% LAB07_DW.HILReadEncoder_PWORK
	  section.data(1).logicalSrcIdx = 7;
	  section.data(1).dtTransOffset = 0;
	
	  ;% LAB07_DW.HILWriteAnalog_PWORK
	  section.data(2).logicalSrcIdx = 8;
	  section.data(2).dtTransOffset = 1;
	
	  ;% LAB07_DW.Posistion_PWORK.LoggedData
	  section.data(3).logicalSrcIdx = 9;
	  section.data(3).dtTransOffset = 2;
	
	  ;% LAB07_DW.Vmy_PWORK.LoggedData
	  section.data(4).logicalSrcIdx = 10;
	  section.data(4).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(3) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% LAB07_DW.HILInitialize_ClockModes
	  section.data(1).logicalSrcIdx = 11;
	  section.data(1).dtTransOffset = 0;
	
	  ;% LAB07_DW.HILInitialize_QuadratureModes
	  section.data(2).logicalSrcIdx = 12;
	  section.data(2).dtTransOffset = 1;
	
	  ;% LAB07_DW.HILInitialize_InitialEICounts
	  section.data(3).logicalSrcIdx = 13;
	  section.data(3).dtTransOffset = 3;
	
	  ;% LAB07_DW.HILReadEncoder_Buffer
	  section.data(4).logicalSrcIdx = 14;
	  section.data(4).dtTransOffset = 5;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(4) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% LAB07_DW.InverseModulus1_FirstSample
	  section.data(1).logicalSrcIdx = 15;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(5) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (dwork)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    dworkMap.nTotData = nTotData;
    


  ;%
  ;% Add individual maps to base struct.
  ;%

  targMap.paramMap  = paramMap;    
  targMap.signalMap = sigMap;
  targMap.dworkMap  = dworkMap;
  
  ;%
  ;% Add checksums to base struct.
  ;%


  targMap.checksum0 = 2101524737;
  targMap.checksum1 = 3363252869;
  targMap.checksum2 = 1761810848;
  targMap.checksum3 = 2824623708;

