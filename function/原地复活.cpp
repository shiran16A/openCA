void* 原地复活(void* arg) {
    isCoordinateRecorded = false;  
    isSpeed = false;      
    while(原地复活开关)
    {
        long int 原地复活坐标Y = ReadZZ(ReadZZ(Cb + 0x6EE150) + 0x3D0 - B) + 0xC4 - B;
        long int 原地复活坐标X = ReadZZ(ReadZZ(Cb + 0x6EE150) + 0x3D0 - B) + 0xC8 - B;
        long int 原地复活坐标Z = ReadZZ(ReadZZ(Cb + 0x6EE150) + 0x3D0 - B) + 0xCC - B;       
        long int run = ReadZZ(Cb + 0x6EE150) + 0xB44 - B;
        long speed1 = ReadZZ(ReadZZ(Cb + 0x6EE150) + 0x3F0 - B) + 0xB8 - B;
        long speed2 = ReadZZ(ReadZZ(Cb + 0x6EE150) + 0x3F0 - B) + 0xC4 - B;       
        
        long int bloodvolume = ReadZZ(ReadZZ(Cb + 0x6EE150) + 0x3F0 - B) + 0x80 - B;
        int volume = ReadFloat(bloodvolume);
        if (volume < 0)
		{
            if (!isCoordinateRecorded) {
              死亡前坐标x = ReadDword(原地复活坐标X);
              死亡前坐标y = ReadDword(原地复活坐标Y);
              死亡前坐标z = ReadDword(原地复活坐标Z);
              isCoordinateRecorded = true;
            }
            miniworld = -150;
        }
        else
        {
          if (miniworld < 0)
            {                
             while (miniworld < 0)
              {    
                int value1 = ReadDword(原地复活坐标X);
                int value2 = ReadDword(原地复活坐标Y);
                int value3 = ReadDword(原地复活坐标Z);

                if (abs(value1 - 死亡前坐标x) > 100 || abs(value2 - 死亡前坐标y) > 100 || abs(value3 - 死亡前坐标z) > 100)
                {                 
                   miniworld = -20;
                }             
                
                if (value1 < 死亡前坐标x)
                 {
                    value1 += 45;
                 }
                 else 
                 if (value1 > 死亡前坐标x)
                 {
                    value1 -= 45;
                 }

                 if (value2 < 死亡前坐标y)
                 {
                    value2 += 45;
                 }
                 else
                 if (value2 > 死亡前坐标y)
                 {
                    value2 -= 45;
                 }

                 if (value3 < 死亡前坐标z)
                 {
                    value3 += 45;
                 }
                 else 
                 if (value3 > 死亡前坐标z)
                 {
                     value3 -= 45;
                 }
                 
                 WriteFloat(run,1);
                 WriteFloat(speed1,999);
                 WriteFloat(speed2,999);
                 isSpeed=true;                             
                 WriteDword(原地复活坐标X, value1);
                 WriteDword(原地复活坐标Y, value2);
                 WriteDword(原地复活坐标Z, value3);    
                 usleep(300);                           
                 miniworld++;    
             }
          }
          else
          {
              if(isSpeed)
              {
                 WriteFloat(speed1,10);
                 WriteFloat(speed2,10);
                 isSpeed=false;
                 isCoordinateRecorded = false;    
              }
              isCoordinateRecorded = false;    
          }
         }
       }
       return NULL;
}