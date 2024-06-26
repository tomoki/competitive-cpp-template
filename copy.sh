for dir in "$@"
do
    mkdir -p $dir
    cp -r $(dirname "$0")/.vscode       $dir
    cp -r $(dirname "$0")/test          $dir
    rm -r $dir/test/*.stderr
    rm -r $dir/test/*.stdout
    cp -r $(dirname "$0")/main.cpp      $dir
    cp -r $(dirname "$0")/.clang-format $dir
    cp -r $(dirname "$0")/.editorconfig $dir
    cp -r $(dirname "$0")/.gitignore    $dir
    cp -r $(dirname "$0")/CMakeLists.txt $dir
done

