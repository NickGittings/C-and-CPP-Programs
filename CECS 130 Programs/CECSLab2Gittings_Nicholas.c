#include <stdio.h>
#include <stdlib.h>

/*
Nick Gittings
CECS 130-01
Currency Converter
*/

int main(){
	
	// Initilizing Variables
	const float fAmount;
	const float fGBP_ratio = .72;
	const float fBTC_ratio = .000099;
	const float fEuro_ratio = .82;
	const float fJPY_ratio = 110.82;
	const float fMXN_ratio = 18.59;
	
	// Console IO
	printf("Enter an amount: ");
	scanf("%f", &fAmount);
	
	// Currency Conversions
	float fUSDtoGBP = (fAmount * .72);
	float fUSDtoBTC = (fAmount * .000099);
	float fUSDtoEuro = (fAmount * .82);
	float fUSDtoJPY = (fAmount * 110.82);
	float fUSDtoMXN = (fAmount * 18.59);
	float fGBPtoUSD = (fAmount / fGBP_ratio);
	float fGBPtoBTC = (fAmount / fGBP_ratio) * fBTC_ratio;
	float fGBPtoEuro = (fAmount / fGBP_ratio) * fEuro_ratio;
	float fGBPtoJPY = (fAmount / fGBP_ratio) * fJPY_ratio;
	float fGBPtoMXN = (fAmount / fGBP_ratio) * fMXN_ratio;
	float fBTCtoUSD = (fAmount / fBTC_ratio);
	float fBTCtoGBP = (fAmount / fBTC_ratio) * fGBP_ratio;
	float fBTCtoEuro = (fAmount / fBTC_ratio) * fEuro_ratio;
	float fBTCtoJPY = (fAmount / fBTC_ratio) * fJPY_ratio;
	float fBTCtoMXN = (fAmount / fBTC_ratio) * fMXN_ratio;
	float fEurotoUSD = (fAmount / fEuro_ratio);
	float fEurotoBTC = (fAmount / fEuro_ratio) * fBTC_ratio;
	float fEurotoGBP = (fAmount / fEuro_ratio) * fGBP_ratio;
	float fEurotoJPY = (fAmount / fEuro_ratio) * fJPY_ratio;
	float fEurotoMXN = (fAmount / fEuro_ratio) * fMXN_ratio;
	float fJPYtoUSD = (fAmount / fJPY_ratio);
	float fJPYtoBTC = (fAmount / fJPY_ratio) * fBTC_ratio;
	float fJPYtoEuro = (fAmount / fJPY_ratio) * fEuro_ratio;
	float fJPYtoGBP = (fAmount / fJPY_ratio) * fJPY_ratio;
	float fJPYtoMXN = (fAmount / fJPY_ratio) * fMXN_ratio;
	float fMXNtoUSD = (fAmount / fMXN_ratio);
	float fMXNtoBTC = (fAmount / fMXN_ratio) * fBTC_ratio;
	float fMXNtoEuro = (fAmount / fMXN_ratio) * fEuro_ratio;
	float fMXNtoJPY = (fAmount / fMXN_ratio) * fJPY_ratio;
	float fMXNtoGBP = (fAmount / fMXN_ratio) * fMXN_ratio;
	
	// Creating Table
	printf("%15s%15s%15s%15s%15s%15s\n", "USD", "GBP", "BTC", "EURO", "JPY", "MXN");
	printf("%16.2f %14.2f %18f %9.2f %17.2f %13.2f \n", fAmount, fUSDtoGBP, fUSDtoBTC, fUSDtoEuro, fUSDtoJPY, fUSDtoMXN);
	printf("%16.2f %14.2f %18f %9.2f %17.2f %13.2f \n", fGBPtoUSD, fAmount, fGBPtoBTC, fGBPtoEuro, fGBPtoJPY, fGBPtoMXN);
	printf("%16.2f %14.2f %18f %9.2f %17.2f %13.2f \n", fBTCtoUSD, fBTCtoGBP, fAmount, fBTCtoEuro, fBTCtoJPY, fBTCtoMXN);
	printf("%16.2f %14.2f %18f %9.2f %17.2f %13.2f \n", fEurotoUSD, fEurotoGBP, fEurotoBTC, fAmount, fEurotoJPY, fEurotoMXN);
	printf("%16.2f %14.2f %18f %9.2f %17.2f %13.2f \n", fJPYtoUSD, fJPYtoGBP, fJPYtoBTC, fJPYtoEuro, fAmount, fJPYtoMXN);
	printf("%16.2f %14.2f %18f %9.2f %17.2f %13.2f \n", fMXNtoUSD, fMXNtoGBP, fMXNtoBTC, fMXNtoEuro, fMXNtoJPY, fAmount);
	
	return 0;
}
