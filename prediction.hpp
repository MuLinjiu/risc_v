//
// Created by Xialin He on 2021/7/5.
//

#ifndef MAIN_CPP_PREDICTION_HPP
#define MAIN_CPP_PREDICTION_HPP
struct predict{
    int first = 0;
    int second = 0;
    int right = 0;
    int wrong = 0;
    void adjust(bool flag){
        if(first == 0 && second == 0){
            if(flag)second = 1;
        }else if(first == 0 && second == 1){
            if(flag){
                first = 1, second = 0;
            }
            else second = 0;
        }else if(first == 1 && second == 0){
            if(flag)second = 1;
            else {
                first = 0;
                second = 1;
            }
        }else if(first == 1 && second == 1){
            if(!flag)second = 0;
        }
    }
    bool jump(){
        return first == 1;
    }
}pred[1000000];
struct P{
    double efficiency() const{
        unsigned int correct = 0,wrong = 0;
        for(int i = 0;i < 10000;++i){
            correct += pred[i].right;
            wrong += pred[i].wrong;
        }
        return (double) correct / (correct + wrong);
    }

}PRE;
#endif //MAIN_CPP_PREDICTION_HPP
