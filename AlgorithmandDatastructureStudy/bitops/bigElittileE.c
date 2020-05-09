int main() {
int a=1;
if(*((char*)&a)==0)
    printf("Big Endian\n");
else
    printf("LittleEndinga\n");

return 0;

}
