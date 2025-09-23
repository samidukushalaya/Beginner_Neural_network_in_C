#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

float sigmoid(float x){
    return 1.0f / (1.0f + exp(-x));
}

float sigmoid_derivative(float x){
    return x*(1-x);
}

int main(){
    srand(time(NULL));

    float input[4][2] ={{0,0},{0,1},{1,0},{1,1}};
    float expeted [4]={0,0,0,1};

    float weights[2];
    float bias = (float)rand()/ RAND_MAX;

    for (int i=0;i<2;i++){
        weights[i] = (float)rand()/ RAND_MAX;
    }

    float lr = 0.1;
    int test = 20000;

    for (int epoch = 0; epoch < test;epoch++){
        printf("Epoch %d\n",epoch);
        for (int i=0;i<4;i++){
            float x1 = input[i][0];
            float x2 = input[i][1];

            float z= x1 *weights[0]+ x2 * weights[1]+bias;
            float output = sigmoid(z);

            float error = expeted[i] -output;
            float delta = error * sigmoid_derivative(output);

            weights[0] += lr * delta * x1;
            weights[1] += lr * delta * x2;

            bias += lr * delta;
        }
    }

    printf("Testing.... trained AND gate:\n");
    for(int i= 0 ; i<4;i++){
        float x1 =input[i][0];
        float x2=input[i][1];

        float z = x1* weights[0] + x2 * weights[1] + bias;

        float output = sigmoid(z);
        printf("Input: %.0f %.0f -> Predicted: %4f\n",x1,x2,output);
    }

    return 0;

}