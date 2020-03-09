/*
    LEETCODE 13 - ROMAN TO INTEGER
    
    coded by Fatih Cinar
    on March 7th, 2020
*/


public class Roman
{
    private final int I = 1;
    private final int IV = 4;
    private final int V = 5;
    private final int IX = 9;
    private final int X = 10;
    private final int XL = 40;
    private final int L = 50;
    private final int XC = 90;
    private final int C = 100;
    private final int CD = 400;
    private final int D = 500;
    private final int CM = 900;
    private final int M = 1000;

    private final int[] allValues = {M, CM, D, CD, C, XC, L, XL, X, IX, V, IV, I};

    private final int numberOfAllValues = 13;



    public static void main(String[] args){
        System.out.println("Introduction");

        Roman romanConversionObject = new Roman();

        String romanForm = romanConversionObject.integerToRoman(1994);


        System.out.println(romanForm);
    }

    private String getRomanCounterpart(int singleValue){
        /*
            This method gets a single-value
            and returns its Roman counterpart
            e.g. gets 4 , returns IV string
        */

        switch (singleValue) {
            case I:
                return "I";
            case IV:
                return "IV";
            case V:
                return "V";
            case IX:
                return "IX";
            case X:
                return "X";
            case XL:
                return "XL";
            case L:
                return "L";
            case XC:
                return "XC";
            case C:
                return "C";
            case CD:
                return "CD";
            case D:
                return "D";
            case CM:
                return "CM";
            case M:
                return "M";
            default:
                return "";

        }

    }


    public String integerToRoman(int value){

        String romanForm = "";

        for(int iterator = 0; iterator < numberOfAllValues; iterator++){

            int valueNow = allValues[iterator];

            while(value >= valueNow){

                value -= valueNow;

                romanForm += getRomanCounterpart(valueNow);
            }

        }

        return romanForm;
        
    }

    
}
