add_executable(prj11 main.c)

# 以下をコメントアウトすると、assertで失敗するようになる
add_definitions(-DNDEBUG)
