compile_cmd=g++
@REM source_files=Histogram.cpp TestHistogram.cpp
set exe_file=MatheFuncDemo.exe
set libformatSDK_folder=%~dp0..\..\thirdParty\formatSDK\windows
echo %libformatSDK_folder%
set target_sdk_static_lib=%~dp0..\..\thirdParty\formatSDK\windows\formatSDK.a
g++ MatheFuncDemo.cpp -O0 -I%libformatSDK_folder% -static %target_sdk_static_lib% -o %exe_file%
.\%exe_file% 30
del  %exe_file%