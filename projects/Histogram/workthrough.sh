compile_cmd=g++
source_files="Histogram.cpp TestHistogram.cpp"
exe_file=Histogram_exe
libformatSDK_folder=../../thirdParty/formatSDK/linux
target_sdk_static_lib=${libformatSDK_folder}/formatSDK.a
${compile_cmd} ${source_files} -I${libformatSDK_folder} -static ${target_sdk_static_lib} -o ${exe_file} 
