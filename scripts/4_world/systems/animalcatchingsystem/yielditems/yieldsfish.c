// modded class FishYieldItemBase : YieldItemBase{

//     // protected array<float> m_HourlyCycleLengthCoefsArray;

//     // float ConvertCatchTimes(array<float> input, out float[] output){
//     //     input;
//     //     output[24];
//     //     float fishing_coefs[24];
//     //     for(int i = 0; i < 24; i++) {
//     //         fishing_coefs[i] = input[i];
//     //     }
//     //     output = fishing_coefs;
//     //     Print(output);
//     //     return output;
//     // }

//     // override float GetCycleTimeForYieldItem(CatchingContextFishingRodAction ctx)
// 	// {
//     //     float m_HourlyCycleLengthCoefsConverted[24];
//     //     m_HourlyCycleLengthCoefsConverted = ConvertCatchTimes(m_HourlyCycleLengthCoefsArray, m_HourlyCycleLengthCoefsConverted)
// 	// 	int hour = Math.Floor(GetGame().GetDayTime());
// 	// 	float res = Math.Lerp(UAFishingConstants.CYCLE_LENGTH_MIN,UAFishingConstants.CYCLE_LENGTH_MAX,m_HourlyCycleLengthCoefsConverted[hour]);
//     //     Print("[gebsfish] [DEBUG]");
//     //     Print(m_HourlyCycleLengthCoefsArray);
//     //     Print(m_HourlyCycleLengthCoefsConverted);
//     //     Print("[gebsfish] [DEBUG]");
//     //     Print(res);
// 	// 	return res;
// 	// }
// }