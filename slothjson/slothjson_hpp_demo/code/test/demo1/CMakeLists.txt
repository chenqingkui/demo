cmake_minimum_required(VERSION 2.6)
SET(PROJECT sloth_json_demo_1)

# 库文件的输出路径
#源码
FILE(GLOB_RECURSE SRC_LIST "*.c" "*.cpp" "*.h")

# 头文件
include_directories(
	.
	${DIR_INCLUDE}
	${DIR_INCLUDE}/rapidjson
	${DIR_INCLUDE}/slothjson
	)

message(STATUS "Current Dir: " ${CMAKE_CURRENT_SOURCE_DIR})



#平台无关库
SET(COMMON_LIBS 

	)
#平台特定库
IF(WIN32)	
	SET(PLATFORM_LIBS )	
ELSEIF(UNIX)
	SET(PLATFORM_LIBS )
ENDIF()

IF(WIN32)
		#LIST(APPEND COMMON_LIBS 	
		#			debug		
		#			optimized   
		#		)	
ELSE()
		LIST(APPEND COMMON_LIBS 	
					debug		pthread 
					debug		rt
					optimized   pthread
					optimized   rt
				)	
ENDIF()			




#编译
add_executable(${PROJECT} ${SRC_LIST})

#Debug版本后缀
set_target_properties(${PROJECT} PROPERTIES DEBUG_POSTFIX "d")

#连接库
target_link_libraries(${PROJECT}  ${COMMON_LIBS} ${PLATFORM_LIBS} )




