cmake_minimum_required(VERSION 3.0 FATAL_ERROR)

project(redis3.0 VERSION 3.0)

set(CMAKE_BUILD_TYPE "Debug")

#message(STATUS "Host is: ${CMAKE_HOST_SYSTEM}.  Build target is: ${CMAKE_SYSTEM}")
get_filename_component(REDIS_ROOT "${CMAKE_CURRENT_SOURCE_DIR}" ABSOLUTE)
#message(STATUS "Project root directory is: ${REDIS_ROOT}")

add_subdirectory(deps)

set(SRC_SERVER src/redis.c
        src/adlist.c
        src/ae.c
#        src/ae_epoll.c
#        src/ae_evport.c
#        src/ae_select.c
#        src/ae_kqueue.c
        src/anet.c
        src/aof.c
        src/asciilogo.h
        src/bio.c
        src/bitops.c
        src/blocked.c
        src/cluster.c
        src/config.c
        src/crc64.c
        src/crc16.c
        src/db.c
        src/debug.c
        src/dict.c
        src/endianconv.c
        src/hyperloglog.c
        src/intset.c
        src/latency.c
        src/lzf_c.c
        src/lzf_d.c
        src/memtest.c
        src/multi.c
        src/networking.c
        src/notify.c
        src/object.c
        src/pqsort.c
        src/pubsub.c
        src/rand.c
        src/rdb.c
        src/release.c
        src/replication.c
        src/rio.c
        src/scripting.c
        src/sds.c
        src/sentinel.c
        src/setproctitle.c
        src/sha1.c
        src/slowlog.c
        src/sort.c
        src/sparkline.c
        src/syncio.c
        src/t_hash.c
        src/t_list.c
        src/t_set.c
        src/t_string.c
        src/t_zset.c
        src/util.c
        src/ziplist.c
        src/zipmap.c
        src/zmalloc.c
        )

set(EXECUTABLE_OUTPUT_PATH src)
link_directories(deps/linenoise deps/lua/src deps/hiredis)
add_executable(redis-server ${SRC_SERVER})

target_include_directories(redis-server
        PRIVATE ${REDIS_ROOT}/deps/linenoise
        PRIVATE ${REDIS_ROOT}/deps/hiredis
        PRIVATE ${REDIS_ROOT}/deps/lua/src
        )
target_link_libraries(redis-server
        PRIVATE pthread
        PRIVATE dl
        PRIVATE m
        PRIVATE lua
        PRIVATE linenoise
        PRIVATE hiredis
        )


set(CLIENT_SRC src/redis-cli.c
        src/anet.c src/sds.c src/adlist.c src/zmalloc.c
        src/release.c src/anet.c src/ae.c src/crc64.c
        )
add_executable(redis-cli ${CLIENT_SRC})

target_include_directories(redis-cli
        PRIVATE ${REDIS_ROOT}/deps/linenoise
        PRIVATE ${REDIS_ROOT}/deps/hiredis
        PRIVATE ${REDIS_ROOT}/deps/lua/src
        )
target_link_libraries(redis-cli
        PRIVATE pthread
        PRIVATE m
        PRIVATE linenoise
        PRIVATE hiredis
        )
