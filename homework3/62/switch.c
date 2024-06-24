typedef enum {MODE_A, MODE_B, MODE_C, MODE_D, MODE_E} mode_t;
long switch1(long* p1, long* p2, mode_t action)
{
    long result = 0;
    switch(action)
    {
    case MODE_E:
        result = 27;
        return result;
    case MODE_A:
        result = *p2;
        *p2 = *p1;
        return result;
    case MODE_B:
        result = *p1 + *p2;
        *p1 = result;
        return result;
    case MODE_C:
        *p1 = 59;
        result = *p2;
        return result;
    case MODE_D:
        *p1 = *p2;
        result = 27;
        return result;
    default:
        result = 12;
    }
    return result;
}