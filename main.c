//
//  main.c
//  gracet C
//
//  Created by stitchmos on 2015/6/1.
//  Copyright (c) 2015年 WMLAB @NCU. All rights reserved.
//

#include <stdio.h>
typedef struct Grafcet{
    int x0;
    int x1;
    int x2;
    int x3;
    int x4;
    int x5;
    int x6;
    
    int R0;
    int R1;
    int R2;
    int R3_4;
    int R5;
    int R6;
    
    int x50;
    int x51;
    int R50;
    
}GG;


void grafcet_G0(GG*);
void action_G0(GG*);
void initial_G0(GG*);

void grafcet_G1_2(GG*);
void runBrushTooth(GG*);
void transmitData(GG*);

void grafcet_G3(GG*);
void getSmartSensorValue(GG*);

void grafcet_G4(GG*);
void showResult(GG*);

void grafcet_G5(GG*);
void goSubGrafcet_G50(GG*);
void action_G50(GG*);

void grafcet_G50(GG*);
void initial_G5(GG*);

void grafcet_G51(GG*);
void getGesture(GG*);

void grafcet_G6(GG*);
void turnoff();

int main(int argc, const char * argv[]) {
    // insert code here...
    GG G;
    G.x0 = 1;
    G.x1 = 0;
    G.x2 = 0;
    G.x3 = 0;
    G.x4 = 0;
    G.x5 = 0;
    G.x6 = 0;
    
    G.R0 = 0;
    G.R1 = 0;
    G.R2 = 0;
    G.R3_4 = 0;
    G.x50 = 0;
    G.x51 = 0;
    
    G.R5 = 0;
    G.R50 = 0;
    G.R6 = 0;
    
    while(1){
        grafcet_G0(&G);
    }
    return 0;
}

/*
    Operation System: 可以做多功作業(類似multi-thread)
    Control sub-driver
*/
void grafcet_G0(GG *G){
    
    if(G->x0 == 1 && G->R0 == 1) grafcet_G1_2(G);
    
    //平行運作
    if(G->x1 == 1 && G->R1 == 1) grafcet_G3(G);
    if(G->x2 == 1 && G->R2 == 1) grafcet_G4(G);


    //合併
    if(G->x3 == 1 && G->x4 == 1 && G->R3_4 == 1)
        grafcet_G5(G);
    
    if(G->x5 == 1 ){
        //繼續抓資料, G1_2()
        if (G->R5 == 1) grafcet_G1_2(G);
        //結束, G6()
        else if(G->R6 ==1) grafcet_G6(G);
    }
    
    action_G0(G);
}

void action_G0(GG *G){
    if(G->x0 == 1) initial_G0(G);
    if(G->x1 == 1) runBrushTooth(G);
    if(G->x2 == 1) transmitData(G);
    if(G->x3 == 1) getSmartSensorValue(G);
    if(G->x4 == 1) showResult(G);
    if(G->x5 == 1) goSubGrafcet_G50(G);
    if(G->x6 == 1) turnoff();
}

void initial_G0(GG *G){
    G->R0 = 1;
    printf("0\n");
};

//goSubGrafcet_G50
void goSubGrafcet_G50(GG *G){
    //第一次進來G50, active G->x50
    if(G->x50 == 0 && G->x51 == 0) grafcet_G50(G);
    if(G->x50 == 1 && G->R50 == 1) grafcet_G51(G);
    action_G50(G);
}

//action_G50
void action_G50(GG *G){
    if(G->x50 == 1) initial_G5(G);
    if(G->x51 == 1) getGesture(G);
}

void grafcet_G1_2(GG *G){
    G->x0 = 0;
    G->x1 = 1;
    G->x2 = 1;
    if (G->x5 == 1) {
        G->x5 = 0;
    }
}

void runBrushTooth(GG *G){
     G->R5 = 0;
    G->R0 = 0;
    G->R1 = 1;
    printf("1\t\t");
};

void grafcet_2(GG *G){
    G->x0 = 0;
    G->x1 = 1;
    G->x2 = 1;
}

void transmitData(GG *G){
    G->R0 = 0;
    G->R2 = 1;
    printf("2\n");
};

void grafcet_G3(GG *G){
    G->x1 = 0;
    G->x3 = 1;
}

void getSmartSensorValue(GG *G){
    G->R1 = 0;
    printf("3\t\t");
};

void grafcet_G4(GG *G){
    G->x2 = 0;
    G->x4 = 1;
}

void showResult(GG *G){
    G->R2 = 0;
    G->R3_4 = 1;
    printf("4\n");
    
};

void grafcet_G5(GG *G){
    G->x3 = 0;
    G->x4 = 0;
    G->x5 = 1;
}

void grafcet_G50(GG *G){
    G->x50 = 1;
}

void initial_G5(GG *G){
    G->R3_4 = 0;
    G->R50 = 1;
    printf("50\n");
};

void grafcet_G51(GG *G){
    G->x50 = 0;
    G->x51 = 1;
}

void getGesture(GG *G){
    G->x51 = 0;
    G->R50 = 0;
    G->R5 = 1;
    printf("51\n");
    printf("================\n");
};

void grafcet_G6(GG *G){
    G->x5 = 0;
    G->x6 = 1;
}

void turnoff(){
    printf("Bye! \n");
}
