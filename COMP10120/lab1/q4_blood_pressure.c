/*
 * Author: Rajit Banerjee, 18202817
 * Pset 1, Q4
 * 29.01.2019
 */

#include <stdio.h>

int main(void)
{
    //variables for systolic and diastolic pressure
    int systolic;
    int diastolic;

    //Input systolic pressure value
    printf("\nSystolic pressure  (mmHg): ");
    scanf("%d", &systolic);

    //Input diastolic pressure value
    printf("Diastolic pressure (mmHg): ");
    scanf("%d", &diastolic);
    

    /* Categories: 
     * http://www.bloodpressureuk.org/BloodPressureandyou/Thebasics/Bloodpressurechart
     */


    //Case A: High blood pressure
    /* if your top number is 140 or more - 
     * then you may have high blood pressure, regardless of your bottom number.
     *    
     * if your bottom number is 90 or more - 
     * then you may have high blood pressure, regardless your top number.
     * 
     * 140 over 90 (140/90) or higher (over a number of weeks): 
     *    You may have high blood pressure (hypertension). 
     *    Change your lifestyle - see your doctor or nurse and take any 
     *    medicines they may give you.
     */
    if (systolic >= 140 || diastolic >= 90)
        printf("\nHigh blood pressure.\n");


    //Case B: Pre-high blood pressure
    /* More than 120 over 80 and less than 140 over 90 (120/80-140/90): 
     *    You have a normal blood pressure reading but it is a little higher 
     *    it should be, and you should try to lower it. Make healthy changes 
     *    to your lifestyle.
     */
    else if (systolic > 120 || diastolic > 80)
        printf("\nPre-high blood pressure.\n");


    //Case C: Ideal blood pressure
    /* More than 90 over 60 (90/60) and less than 120 over 80 (120/80): 
     *    Your blood pressure reading is ideal and healthy. 
     *    Follow a healthy lifestyle to keep it at this level.
     */
    else if (systolic > 90 || diastolic > 60)
        printf("\nIdeal blood pressure.\n");


    //Case D: Low blood pressure
    /* if your top number is 90 or less - 
     * then you may have low blood pressure, regardless of your bottom number.
     * 
     * if your bottom number is 60 or less - 
     * then you may have low blood pressure, regardless of your top number.
     * 
     * 90 over 60 (90/60) or less: You may have low blood pressure.
     */
    else
        printf("\nLow blood pressure.\n");
    
    return 0;
}
