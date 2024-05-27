void* 锁定高度(void* arg) {
    long int a1 = ReadZZ(ReadZZ(Cb + 0x6EE150) + 0x3D0 - B) + 0xC8 - B;
    int y = ReadDword(a1);		
    while(锁定高度开关)
    {              
        WriteDword(a1,y);
		usleep(3000);
    }
    return NULL;
}