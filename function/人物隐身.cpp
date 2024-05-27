JNIEXPORT void JNICALL 
Java_mini_tencent_ca_Jni_hide(JNIEnv* env,jobject obj, jboolean setbool) {
    long int Heighttransfer = ReadZZ(ReadZZ(Cb + 0x6EE150) + 0x3D0 - B) + 0xC8 - B;
    long int bigpeople_true = ReadZZ(Cb + 0x6EE150) + 0x510 - B;
    long gravity = ReadZZ(Cd + 0x1928) + 0xB88;
    int y = ReadDword(Heighttransfer);    
    if(setbool)
    {
        XaWriteFloat(gravity, 0);
        int value = y + 13500;          
        WriteDword(Heighttransfer, value);
	    WriteFloat(bigpeople_true, -88);       
    }
    else
    {
        XaWriteFloat(gravity, 8);
        int value = y - 13500;          
        WriteDword(Heighttransfer, value);
	    WriteFloat(bigpeople_true, 1);
    }
}