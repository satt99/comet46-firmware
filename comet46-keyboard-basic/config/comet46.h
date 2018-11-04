#ifdef COMPILE_LEFT
    #define PIPE_NUMBER 0
    #define S01 3
    #define S02 4
    #define S03 5
    #define S04 2
    #define S05 0
    #define S06 1
    #define S07 30
    #define S08 29
    #define S09 28
    #define S10 25
    #define S11 24
    #define S12 23
    #define S13 22
    #define S14 21
    #define S15 17
    #define S16 12
    #define S17 18
    #define S18 19
    #define S19 20
    #define S20 13
    #define S21 16
    #define S22 15
    #define S23 14
#endif

#ifdef COMPILE_RIGHT
    #define PIPE_NUMBER 1
    #define S01 1
    #define S02 0
    #define S03 30
    #define S04 2
    #define S05 4
    #define S06 3
    #define S07 5
    #define S08 8
    #define S09 9
    #define S10 12
    #define S11 13
    #define S12 14
    #define S13 15
    #define S14 16
    #define S15 17
    #define S16 25
    #define S17 18
    #define S18 19
    #define S19 20
    #define S20 24
    #define S21 21
    #define S22 22
    #define S23 23
#endif

#define INPUT_MASK (1<<S01 | \
                    1<<S02 | \
                    1<<S03 | \
                    1<<S04 | \
                    1<<S05 | \
                    1<<S06 | \
                    1<<S07 | \
                    1<<S08 | \
                    1<<S09 | \
                    1<<S10 | \
                    1<<S11 | \
                    1<<S12 | \
                    1<<S13 | \
                    1<<S14 | \
                    1<<S15 | \
                    1<<S16 | \
                    1<<S17 | \
                    1<<S18 | \
                    1<<S19 | \
                    1<<S20 | \
                    1<<S21 | \
                    1<<S22 | \
                    1<<S23)

// Low frequency clock source to be used by the SoftDevice
#define NRF_CLOCK_LFCLKSRC      {.source        = NRF_CLOCK_LF_SRC_XTAL,            \
                                 .rc_ctiv       = 0,                                \
                                 .rc_temp_ctiv  = 0,                                \
                                 .xtal_accuracy = NRF_CLOCK_LF_XTAL_ACCURACY_20_PPM}
