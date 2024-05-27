void* 头部旋转(void* arg) {
    float zhi = 0;
    while(头部旋转开关)
    {
        long int a1 = ReadZZ(ReadZZ(Cb + 0x6EE150) + 0x260 - B) + 0x54 - B;
        zhi = fmod(zhi + 1, 361);
        WriteFloat(a1, zhi);
	    usleep(头部旋转速度);
    }
    return NULL;
}