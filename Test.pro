TEMPLATE = app
TARGET = 
DEPENDPATH += .
INCLUDEPATH += "includes"
LIBS += -L"libs" -lPCA  \
				 -lImage -lDrawing -lLine -lEdge  -lPoint -lMatrix -lCanny -lConverter -lCrossCorrelation -lDescriptorDistance \
				 -lGeometricHistgoram -lGHTInPoint -lImageConvert -lReader -lJPEGReader \
		-lLandmarkDetection  -lPHoughTransform -lPHTEntry -lProHoughTransform  -lSegmentation \
		-lShapeHistogram -lSuzuki -lSVD -lThresholds -lTPSReader -lTreatments \		
		-ljcparam -ljcapimin -ljcmarker \
		-ljdapistd -ljdmaster -ljdarith  \
		-ljaricom \
		-ljcomapi \
		-ljctrans -ljdapimin -ljdatadst -ljdatasrc -ljdcoefct -ljdcolor -ljddctmgr \
		-ljdinput -ljdmainct -ljdmarker -ljdmerge -ljdpostct -ljdsample -ljdtrans -ljerror \
		-ljidctflt -ljidctfst -ljidctint -ljmemmgr -ljmemnobs  -ljquant1 -ljquant2 -ljutils -ljcapistd \
		-ljcinit -ljccoefct -ljcprepct -ljchuff -ljdhuff -ljcarith -ljccolor -ljcmaster -ljcmainct -ljcdctmgr -ljcsample \
		-ljfdctint -ljfdctflt -ljfdctfst \
		-L"/usr/lib" -lOpenCL  
SOURCES += Test.cpp
