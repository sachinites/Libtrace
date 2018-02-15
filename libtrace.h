/*
 * =====================================================================================
 *
 *       Filename:  libtrace.h
 *
 *    Description:  Defines the libtrace data structures
 *
 *        Version:  1.0
 *        Created:  Friday 16 February 2018 01:05:18  IST
 *       Revision:  1.0
 *       Compiler:  gcc
 *
 *         Author:  Er. Abhishek Sagar, Networking Developer (AS), sachinites@gmail.com
 *        Company:  Brocade Communications(Jul 2012- Mar 2016), Current : Juniper Networks(Apr 2017 - Present)
 *        
 *        This file is part of the Libtrace distribution (https://github.com/sachinites).
 *        Copyright (c) 2017 Abhishek Sagar.
 *        This program is free software: you can redistribute it and/or modify
 *        it under the terms of the GNU General Public License as published by  
 *        the Free Software Foundation, version 3.
 *
 *        This program is distributed in the hope that it will be useful, but 
 *        WITHOUT ANY WARRANTY; without even the implied warranty of 
 *        MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU 
 *        General Public License for more details.
 *
 *        You should have received a copy of the GNU General Public License 
 *        along with this program. If not, see <http://www.gnu.org/licenses/>.
 *
 * =====================================================================================
 */

#ifndef __LIBTRACE__
#define __LIBTRACE__

#include <stdio.h>
#include "bitsop.h"
#include <stdlib.h>
#include <memory.h>

typedef enum{
    FALSE,
    TRUE
} tr_boolean;

typedef struct {
    
    char b[256];
    unsigned long long bit_mask;
    tr_boolean enable;
} traceoptions;

static inline void
trace_enable(traceoptions *traceopts, tr_boolean enable){
    traceopts->enable = enable;
}

static inline void 
init_trace(traceoptions *traceopts){
    memset(traceopts, 0, sizeof(traceoptions));
}

#define TRACE(traceopts_ptr, bit)                                               \
    if((traceopts_ptr)->enable == TRUE){                                        \
        if(IS_BIT_SET((traceopts_ptr)->bit_mask, bit)){                         \
            printf("%s(%d) : %s\n", __FUNCTION__, __LINE__, (traceopts_ptr)->b);\
            memset((traceopts_ptr)->b, 0, 256);                                 \
        }                                                                       \
}


static inline void
enable_trace_event(traceoptions *traceopts, unsigned long long bit){
    SET_BIT(traceopts->bit_mask, bit);
}

static inline void
disable_trace_event(traceoptions *traceopts, unsigned long long bit){
    UNSET_BIT(traceopts->bit_mask, bit);
}


#endif /* __LIBTRACE__ */
