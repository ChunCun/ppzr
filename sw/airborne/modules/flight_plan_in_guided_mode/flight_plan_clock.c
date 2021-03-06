//
// Created by shuoli on 2016/8/4.
//

#include<std.h>
#include "flight_plan_clock.h"


uint32_t counter_global;  // start when codes are uploaded
uint32_t counter_autopilot_mode; // start when autopilot mode is changed
uint32_t counter_primitive;
uint32_t counter_temp1; // counter for temporarily use
uint32_t counter_temp2; // counter for temporarily use
uint32_t counter_temp3; // counter for temporarily use


bool clock_mask[5];

float time_global;
float time_autopilot_mode;
float time_primitive;
float time_temp1;
float time_temp2;
float time_temp3;

void flight_plan_clock_init(){
    set_bit_ls(clock_mask,0);
    counter_global = 0;
    counter_autopilot_mode = 0;
    counter_primitive = 0;
    counter_temp1 = 0;
    counter_temp2 = 0;
    counter_temp3 = 0;
}

void flight_plan_clock_run() {
    counter_global++;
    counter_autopilot_mode++;
    counter_primitive++;
    time_primitive = counter_primitive/20.0;
    counter_temp1++;
    counter_temp2++;
    counter_temp3++;

    time_global = counter_global/20.0;
    time_autopilot_mode = counter_autopilot_mode/20.0;
    //time_primitive = counter_primitive/20.0;
    time_temp1 = counter_temp1/20.0;
    time_temp2 = counter_temp2/20.0;
    time_temp3 = counter_temp3/20.0;
}