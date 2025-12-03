if [ $# -eq 0 ]; then
    read -p "Enter the path to the CPP file (relative to cpp folder): " filepath
else
    filepath=$1
fi

if [[ ! $filepath == *.cpp ]]; then
    echo "Error: File must have .cpp extension"
    exit 1
fi

if [ ! -f "$filepath" ]; then
    echo "Error: File '$filepath' does not exist"
    exit 1
fi

filename=$(basename -- "$filepath")
basename="${filename%.*}"
dirname=$(dirname "$filepath")

echo "Compiling $filepath"
g++ -o "$dirname/$basename.exe" "$filepath"


if [ $? -eq 0 ]; then
    echo "Compilation successful!"
    echo "Running $basename.exe"
    echo "-------------------------"
    "./$dirname/$basename.exe"
    echo""
    echo "-------------------------"
    echo "Program execution completed with exit code $?"
else
    echo "Compilation failed!"
fi
