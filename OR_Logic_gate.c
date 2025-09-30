#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

float sigmod(float x){
    return 1.0f / (1.0f + exp(-x));

}

float sigmod_derivative(float x){
    return x*(1-x);
}

int main(){
    srand(time(NULL));
    float input[4][2]={{0,0},{0,1},{1,0},{1,1}};
    float expeted [4] = {0,1,1,1};

    float weights[2];
    float bias = (float) rand()/RAND_MAX;

    for (int i = 0; i < 2; i++)
    {
        weights[i] =  (float) rand()/RAND_MAX;
    }
    float lr =0.1;
    int test = 500000;

    for (int tests =0 ;tests < test;tests++){
        printf("Test %d\n",tests);

        for(int i=0;i<4;i++){
            float x1 =input[i][0];
            float x2 = input[i][1];

            float z= x1*weights[0] + x2 * weights[1] + bias;
            float output = sigmod(z);

            float error = expeted[i ]- output;
            float delta = error * sigmod_derivative(output);

            weights[0] += lr * delta *x1;
            weights[1] += lr * delta *x2;

            bias += lr * delta;


        }
    }

    printf("Testing...  Tranied OR gate: \n");

    for (int i=0 ;i<4;i++){
        float z = input[i][0] * weights[0] + input[i][1] * weights[1] + bias;

        float outout =sigmod(z);
        printf("Input : %.0f %.0f -> predicted: %4f\n",input[i][0],input[i][1],outout);
    }

    return 0;
    
}