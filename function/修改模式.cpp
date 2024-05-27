JNIEXPORT void JNICALL
Java_mini_tencent_ca_Jni_model(JNIEnv* env,jobject obj,jint value) {
    long model = ReadZZ(Cb + 0x3C8BD8) + 0xC0 - B;
    WriteDword(model, value);
}
//4 编辑模式 5 玩法模式 2 创造模式 1冒险模式