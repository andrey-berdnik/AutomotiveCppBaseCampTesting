cmake_minimum_required(VERSION 3.1) # Проверка версии CMake.
									# Если версия установленой программы
									# старее указаной, произайдёт аварийный выход.

add_compile_options(-Wc++11-extensions) # CMake 2.8.12 or newer
set(CMAKE_CXX_STANDARD 11) # C++11...
set(CMAKE_CXX_STANDARD_REQUIRED ON) #...is required...
set(CMAKE_CXX_EXTENSIONS OFF) #...without compiler extensions like gnu++11

add_executable(main main.cpp)		# Создает исполняемый файл с именем main
									# из исходника main.cpp

                                    # Set the output folder where your program will be created

project("own realisaton if printf")

