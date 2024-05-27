void* 传送光环(void* arg) {
    while(传送光环开关)
    {
        int team = ReadDword(Cb + 0x62F4);
        long int arrayaddr = ReadZZ(ReadZZ(ReadZZ(Cb + 0x4A60) + 0x88-B) + 0xC0-B) + 0x0-B;
        long int self_x = ReadZZ(ReadZZ(Cb + 0x6EE150) + 0x3D0-B) + 0xC4-B;
        long int self_z = ReadZZ(ReadZZ(Cb + 0x6EE150) + 0x3D0-B) + 0xC8-B;
        long int self_y = ReadZZ(ReadZZ(Cb + 0x6EE150) + 0x3D0-B) + 0xCC-B;
        for (int i = 0; i < 40; i++)
        {
            long int objaddrzz = ReadZZ(arrayaddr + 8 * i);         
            //判断玩家是否退出
            int ObjectExit = ReadDword(objaddrzz - B + 0x2C8);
            if (ObjectExit != 1120403456)
            {
                continue;
            }
            
            // 判断阵营
            int dw = ReadDword(objaddrzz - B + 0x24);
            // 去除队友
            if (team != 0 && (team == dw || dw == 0))
            {
                continue;
            }
            
            int mnh = ReadDword(objaddrzz - B + 0x0);
            char* token = strtok(globalWhitelist, ",");
            while (token != nullptr) {
            int whitelistInt = atoi(token);
            if (mnh == whitelistInt) {
                continue;
            }
                token = strtok(nullptr, ",");
            }

            int d_x = ReadDword(objaddrzz - B + 0x14);
            int d_z = ReadDword(objaddrzz - B + 0x18);
            int d_y = ReadDword(objaddrzz - B + 0x1C);
            WriteDword(self_x, d_x);
            WriteDword(self_z, d_z);
            WriteDword(self_y, d_y);

            usleep(100000);
		}
    }
    return NULL;
}