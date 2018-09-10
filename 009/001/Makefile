#  预处理---->编译------>汇编------>链接
#   a.c ----> a.s ----> a.o + b.o + .....o = test
# gcc -o test a.c b.c
# gcc -o test a.c b.c -v
# 百度搜索 gnu make 于凤昌
# 官方文档 http://www.gnu.org/software/make/manual/


##################################
# 第一版本
#test:a.o b.o
#	gcc -o test a.o b.o

#a.o:a.c
#	gcc -c -o a.o a.c
#b.o:b.c
#	gcc -c -o b.o b.c

##################################
######################
# 通配符 
# % 
# $@ 目标文件
# $< 第一个依赖文件
# $^ 所有依赖文件
# 假想目标 PHONY
# 变量
# 即时变量 A := xxx # A的值即刻确定，在定义时才确定
# 延迟变量 B = xxx  # B的值使用的时候才确定
# ?= 延迟变量, 如果是第一次定义才起作用，如果在前面该变量已经定义，则忽略
# += 附加，   是即时变量或者延迟变量，取决于前面的定义
# 使用变量  $(A)
# 在 echo 前添加 @, 就不会显示命令
# 第二版
#A := $(C)
#B =  $(C)
#C = 123


#test_func:
#	@echo A=$(A) # A 为空
#	@echo B=$(B)

all:a.o b.o
	gcc -o test $^


%.o:%.c
	gcc -c -o $@ $<

clean:
	rm *.o test 



C=abc
#C += abc

# 定义假想目标, 如果目录下存在clean文件，则需要定义假想目标
.PHONY:	clean

####################
# 函数
#  foreach
#  filter
#  filter-out
#  wildcard   取出其中存在的文件
#  patsubstr

######################
# gcc -M c.c # 打印依赖
# gcc -M -MF c.d c.c # 把依赖写入文件c.d
# gcc -c -o c.o c.c -MD -MF c.d # 编译 c.c, 生成 c.o, 把依赖写入 c.d
# CFLAGS 编译参数

