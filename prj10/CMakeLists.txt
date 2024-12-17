add_executable(prj10 main.c)

# 以下をコメントアウトすると、assertで失敗するようになる
add_definitions(-DNDEBUG)
