TEMPLATE = lib

COMMON_DIR = $$(ZND_HOME)/dev/src/Common
HEADERS += $$COMMON_DIR/StringCommon.h 
SOURCES += $$COMMON_DIR/StringCommon.cpp \
           $$COMMON_DIR/SemaphoreCommon.cpp
		   
SOURCES += BpaPRAdequacySetting.cpp \             
			BpaPRParam.cpp \                      
			PRAdequacyBase.cpp \                  
			PRAdequacyEstimate.cpp \              
			PRAdequacyEstimateMisc.cpp \          
			PRAdequacyEstimateResultXml.cpp \     
			PRAdequacyEstimateThread.cpp \        
			PRAdequacyStateEstimate.cpp \         
			PRAdequacyStateEstimateBalance.cpp \  
			PRAdequacyStateSample.cpp \           
			PRCopTable.cpp \                      
			PROverLimitAd.cpp \                   
			PROverLimitAdRadial.cpp \             
			PRSampleAnalytic.cpp \                
			PRSampleBase.cpp \                    
			PRSampleFastSort.cpp \                
			PRSampleMonteCarlo.cpp \              
			PRSampleState.cpp \                   
			PRSecurity.cpp \                      
			PRSecurityFault.cpp \                 
			PRSecurityResult.cpp \                
			PRSecurityThread.cpp \
			LogFile.cpp

HEADERS += BpaPRDataDefine.h \       
		BpaPRParam.h \            
		PRAdequacyBase.h \        
		PRAdequacyBaseExp.h \     
		PRAdequacyEstimate.h \    
		PRAdequacyStateEstimate.h \
		PRAdequacyStateSample.h \ 
		PRCopTable.h \            
		PROverLimitAd.h \         
		PRSampleAnalytic.h \      
		PRSampleBase.h \          
		PRSampleFastSort.h \      
		PRSampleMonteCarlo.h \    
		PRSampleState.h \         
		PRSecurity.h
		

	

!include($$(ZND_HOME)/dev/mkspecs/qmake.conf){
         error(the file $$(ZND_HOME)/dev/mkspecs/qmake.conf is not exist!!)
}

!include(../../../PowerGrid.pri) {
         error(the file ../../../PowerGrid.pri is not exist!!)
}

CONFIG -= qt

win32: LIBS += -lkernel32 -luser32
LIBS += -lBpaMemDb -lPRMemDB -lTinyXML -lDCNetwork
DEFINES += PRADEQUACYBASE_EXPORTS

