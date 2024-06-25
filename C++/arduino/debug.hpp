#ifndef DEBUG_HPP
#define DEBUG_HPP

#if CFG_DEBUG
    #define DEBUG_LVL1      Serial.println
#else
    #define DEBUG_LVL1
#endif

#if CFG_DEBUG == 2
    #define DEBUG_LVL2      Serial.println
#else
    #define DEBUG_LVL2
#endif

#if CFG_DEBUG == 3
    #define DEBUG_LVL3      Serial.println
#else
    #define DEBUG_LVL3
#endif

#endif