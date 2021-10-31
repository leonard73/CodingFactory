#
compile_cmd=g++
source_files="MatheFuncDemo.cpp"
exe_file=MatheFuncDemo_exe
define_flag="-D_COMPLIE_LINUX_"
${compile_cmd} ${source_files} ${define_flag} -o ${exe_file} 
./${exe_file} 30
rm -rf ${exe_file}