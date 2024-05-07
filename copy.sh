mkdir -p $1
cp -r $(dirname "$0")/.vscode       $1
cp -r $(dirname "$0")/test          $1
cp -r $(dirname "$0")/main.cpp      $1
cp -r $(dirname "$0")/.clang-format $1
cp -r $(dirname "$0")/.editorconfig $1
cp -r $(dirname "$0")/.gitignore    $1
cp -r $(dirname "$0")/CMakeLists.txt $1