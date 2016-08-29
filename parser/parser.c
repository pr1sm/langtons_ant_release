//
//  parser.c
//  langtons_ant
//
//  Created by Srinivas Dhanwada on 8/28/16.
//  Copyright © 2016 dhanwada. All rights reserved.
//

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include "parser.h"

int BORDER_MODE = 0;

const char* help_text = "Usage: langtons_ant [options]\n\n"
                        "-c, --cylinder    Run the ant in cylinder mode -- ant will wrap across the\n"
                        "                  x-axis.\n"
                        "-h, --help        Print this help message.\n";

void parse_args(int argc, char** argv) {
    
    if(argc == 1) {
        return;
    }
    
    int flag;
    int help_flag = 0;
    
    opterr = 0;
    
    while(1) {
        static struct option long_options[] = {
            {"cylinder", no_argument, 0, 'c'},
            {"help", no_argument, 0, 'h'},
            {0, 0, 0, 0}
        };
        
        int option_index = 0;
        flag = getopt_long(argc, argv, "ch", long_options, &option_index);
        
        if(flag == -1) {
            break;
        }
        
        switch (flag) {
            case 0:
                if(long_options[option_index].flag != 0) {
                    break;
                }
                printf("option: %s", long_options[option_index].name);
                if(optarg) {
                    printf(" with args %s", optarg);
                }
                printf("\n");
                break;
                
            case 'c':
                BORDER_MODE = 1;
                break;
                
            case 'h':
                help_flag = 1;
                break;
                
            case '?':
                opterr = 1;
                break;
                
            default:
                printf("%s", help_text);
                abort();
        }
    }
    
    if(help_flag || opterr) {
        printf("%s", help_text);
        exit(0);
    }
}
