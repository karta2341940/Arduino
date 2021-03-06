#define ls138a 30
#define ls138b 31
#define ls138c 32
#define output OUTPUT
#define input INPUT
#define high HIGH
#define low LOW
#define row 8
#define col 8
#define delay_time 300

boolean led8[16][8][8]={\
    {\
    0,1,1,1,1,1,1,0,\
    0,1,0,0,0,0,1,0,\
    0,1,0,0,0,0,1,0,\
    0,1,0,0,0,0,1,0,\
    0,1,0,0,0,0,1,0,\
    0,1,0,0,0,0,1,0,\
    0,1,0,0,0,0,1,0,\
    0,1,1,1,1,1,1,0\
    },
    {\
    0,0,0,0,1,1,0,0,\
    0,0,0,1,1,1,0,0,\
    0,0,1,0,1,1,0,0,\
    0,0,0,0,1,1,0,0,\
    0,0,0,0,1,1,0,0,\
    0,0,0,0,1,1,0,0,\
    0,0,1,1,1,1,1,1,\
    0,0,1,1,1,1,1,1\
    },
    {\
    0,0,0,1,1,1,0,0,\
    0,0,1,0,0,0,1,0,\
    0,1,0,0,0,1,0,0,\
    0,0,0,0,1,0,0,0,\
    0,0,0,1,0,0,0,0,\
    0,0,1,0,0,0,0,0,\
    0,1,0,0,0,0,0,0,\
    1,1,1,1,1,1,1,1\
    },
    {\
    0,0,1,1,1,1,1,0,\
    0,1,0,0,0,0,1,0,\
    0,0,0,0,0,0,1,0,\
    0,0,1,1,1,1,1,0,\
    0,0,1,1,1,1,1,0,\
    0,0,0,0,0,0,1,0,\
    0,1,0,0,0,0,1,0,\
    0,0,1,1,1,1,1,0\
    },
    {\
    0,1,0,0,0,1,0,0,\
    0,1,0,0,0,1,0,0,\
    0,1,0,0,0,1,0,0,\
    0,1,0,0,0,1,0,0,\
    0,1,1,1,1,1,1,1,\
    0,0,0,0,0,1,0,0,\
    0,0,0,0,0,1,0,0,\
    0,0,0,0,0,1,0,0\
    },
    {\
    1,1,1,1,1,1,1,1,\
    1,0,0,0,0,0,0,0,\
    1,0,0,0,0,0,0,0,\
    1,1,1,1,1,1,1,1,\
    0,0,0,0,0,0,0,1,\
    0,0,0,0,0,0,0,1,\
    0,0,0,0,0,0,0,1,\
    1,1,1,1,1,1,1,1\
    },
    {\
    0,1,1,1,1,1,1,0,\
    0,1,0,0,0,0,0,0,\
    0,1,0,0,0,0,0,0,\
    0,1,0,0,0,0,0,0,\
    0,1,1,1,1,1,1,0,\
    0,1,0,0,0,0,1,0,\
    0,1,0,0,0,0,1,0,\
    0,1,1,1,1,1,1,0\
    },
    {\
    0,1,1,1,1,1,1,0,\
    0,1,0,0,0,0,1,0,\
    0,1,0,0,0,0,1,0,\
    0,0,0,0,0,1,0,0,\
    0,0,0,0,0,1,0,0,\
    0,0,0,0,1,0,0,0,\
    0,0,0,0,1,0,0,0,\
    0,0,0,0,1,0,0,0\
    },
    {\
    0,0,1,1,1,1,0,0,\
    0,1,0,0,0,0,1,0,\
    0,1,0,0,0,0,1,0,\
    0,0,1,1,1,1,0,0,\
    0,0,1,1,1,1,0,0,\
    0,1,0,0,0,0,1,0,\
    0,1,0,0,0,0,1,0,\
    0,0,1,1,1,1,0,0\
    },
    {\
    0,0,0,1,1,1,1,0,\
    0,0,1,0,0,0,1,0,\
    0,0,1,0,0,0,1,0,\
    0,0,0,1,1,1,1,0,\
    0,0,0,0,0,0,1,0,\
    0,0,0,0,0,0,1,0,\
    0,0,0,0,0,0,1,0,\
    0,0,0,0,0,0,1,0\
    },
    {\
    0,0,0,1,1,0,0,0,\
    0,0,1,0,0,1,0,0,\
    0,1,0,0,0,0,1,0,\
    0,1,0,0,0,0,1,0,\
    0,1,1,1,1,1,1,0,\
    0,1,0,0,0,0,1,0,\
    0,1,0,0,0,0,1,0,\
    0,1,0,0,0,0,1,0\
    },
    {\
    0,1,1,1,1,0,0,0,\
    0,1,0,0,0,1,0,0,\
    0,1,0,0,0,1,0,0,\
    0,1,1,1,1,0,0,0,\
    0,1,1,1,1,0,0,0,\
    0,1,0,0,0,1,0,0,\
    0,1,0,0,0,1,0,0,\
    0,1,1,1,1,0,0,0\
    },
    {\
    0,0,0,1,1,1,1,0,\
    0,1,1,0,0,0,0,0,\
    1,0,0,0,0,0,0,0,\
    1,0,0,0,0,0,0,0,\
    1,0,0,0,0,0,0,0,\
    1,0,0,0,0,0,0,0,\
    0,1,1,0,0,0,0,0,\
    0,0,0,1,1,1,1,0\
    },
    {\
    0,1,1,1,1,0,0,0,\
    0,1,0,0,0,1,0,0,\
    0,1,0,0,0,0,1,0,\
    0,1,0,0,0,0,1,0,\
    0,1,0,0,0,0,1,0,\
    0,1,0,0,0,0,1,0,\
    0,1,0,0,0,1,0,0,\
    0,1,1,1,1,0,0,0\
    },
    {\
    0,1,1,1,1,1,1,0,\
    0,1,1,0,0,0,0,0,\
    0,1,1,0,0,0,0,0,\
    0,1,1,1,1,1,1,0,\
    0,1,1,1,1,1,1,0,\
    0,1,1,0,0,0,0,0,\
    0,1,1,0,0,0,0,0,\
    0,1,1,1,1,1,1,0\
    },
    {\
    0,1,1,1,1,1,1,0,\
    0,1,1,1,1,1,1,0,\
    0,1,1,0,0,0,0,0,\
    0,1,1,0,0,0,0,0,\
    0,1,1,1,1,1,0,0,\
    0,1,1,1,1,1,0,0,\
    0,1,1,0,0,0,0,0,\
    0,1,1,0,0,0,0,0\
    }

};
#define otp OUTPUT
#define inp INPUT
int base1 = 37;
int dipsw[4]={0};
int base =2 ;
boolean led[row][col];
byte rowpin[row] = {2,3,4,5,6,7,8,9};
//8 col
int gt = 0 ;

void setup(){

    InitSW();
    Init8x8();
}
int i = 0;
int bin = 0;
void loop()
{
    
    for( int i = 0 ; i < 4 ; i ++ )
    {
        dipsw[i] = digitalRead(base1+i);
    }
    if(dipsw[0] == 0) bin+=1;
    if(dipsw[1] == 0) bin+=2;
    if(dipsw[2] == 0) bin+=4;
    if(dipsw[3] == 0) bin+=8;
    
    wordtoled(bin);
    displayled(led,1000);
    
    bin = 0;
}

void Init8x8()
{
    for( int i = 30 ; i <= 32 ; i++)
    {
        pinMode(i, OUTPUT);
    }

    for(int i = 2 ; i<=9 ; i++)
    {
        pinMode(i, output);
    }
    clear();
    pinMode(A14, output);
    digitalWrite(A14, low);
}
void InitSW()
{
    int num = 4 ;
    for( int i = base ; i < base+num ; i+=1 )
    {
        pinMode( i , otp );
    }
    for( int i = base1 ; i < base1+num ; i+=1 )
    {
        pinMode( i , INPUT_PULLUP );
    }
    pinMode( A15 , otp );
    digitalWrite( A15 , 0);

}

void wordtoled(int n)
{
    for(int i = 0 ; i < row ; i ++)
    {
        for(int j = 0 ; j < col ; j++)
        {
            led[i][j] = led8[n][j][i];
        }
    }
}

void clear()
{
    for(int i = 0 ; i < row;i++)
    {
        digitalWrite(rowpin[i], low);
    }
}

void displayled(byte led[row][col],int continue1)
{
    for(int k=0;k<continue1;k++)
    {
        for(int i = 0 ; i < col ; i++)
        {
            clear();
            low74138pin(i);
            for(int j=0;j<row;j++)
            {
                if( led[i][j]  ==1 )
                {
                    digitalWrite(rowpin[j], high);
                }
            }
        }
    }
}

void low74138pin(int num)
{
    switch(num){
        case 0:
            digitalWrite(30, 0);
            digitalWrite(31, 0);
            digitalWrite(32, 0);
            break;
        case 1:
            digitalWrite(30,1);
            digitalWrite(31,0);
            digitalWrite(32,0);
            break;
        case 2:
            digitalWrite(30,0);
            digitalWrite(31,1);
            digitalWrite(32,0);
            break;
        case 3:
            digitalWrite(30,1);
            digitalWrite(31,1);
            digitalWrite(32,0);
            break;
        case 4:
            digitalWrite(30,0);
            digitalWrite(31,0);
            digitalWrite(32,1);
            break;
        case 5:
            digitalWrite(30,1);
            digitalWrite(31,0);
            digitalWrite(32,1);
            break;
        case 6:
            digitalWrite(30,0);
            digitalWrite(31,1);
            digitalWrite(32,1);
            break;
        case 7:
            digitalWrite(30,1);
            digitalWrite(31,1);
            digitalWrite(32,1);
            break;            
    }
}








