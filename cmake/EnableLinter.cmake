add_custom_target(
        cpplint
        COMMAND
        mkdir -p lint &&
        cpplint --recursive --exclude=build/* --output=emacs . > ./lint/analyze.txt 2> ./lint/analyze.txt &&
        cat ./lint/analyze.txt &&
        rm -rf lint
        WORKING_DIRECTORY
        ${CMAKE_CURRENT_SOURCE_DIR}
        VERBATIM
)