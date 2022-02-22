echo 'main="$1"; shift'
echo exec "$LDX" '-o "$main" "$main".o ${1+"$@"}'
