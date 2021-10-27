#
compile_cmd=g++
source_files=huffman.cpp
exe_file=huffman_exe
libformatSDK_folder=../../thirdParty/formatSDK/linux
target_sdk_static_lib=${libformatSDK_folder}/formatSDK.a
${compile_cmd} ${source_files} -I${libformatSDK_folder} -static ${target_sdk_static_lib} -o ${exe_file} 