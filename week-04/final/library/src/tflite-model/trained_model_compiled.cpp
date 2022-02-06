/* Generated by Edge Impulse
*
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in
* all copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
* SOFTWARE.
*/
// Generated on: 04.02.2022 11:28:51

#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include "edge-impulse-sdk/tensorflow/lite/c/builtin_op_data.h"
#include "edge-impulse-sdk/tensorflow/lite/c/common.h"
#include "edge-impulse-sdk/tensorflow/lite/micro/micro_mutable_op_resolver.h"
#include "edge-impulse-sdk/porting/ei_classifier_porting.h"

#if EI_CLASSIFIER_PRINT_STATE
#if defined(__cplusplus) && EI_C_LINKAGE == 1
extern "C" {
    extern void ei_printf(const char *format, ...);
}
#else
extern void ei_printf(const char *format, ...);
#endif
#endif

#if defined __GNUC__
#define ALIGN(X) __attribute__((aligned(X)))
#elif defined _MSC_VER
#define ALIGN(X) __declspec(align(X))
#elif defined __TASKING__
#define ALIGN(X) __align(X)
#endif

using namespace tflite;
using namespace tflite::ops;
using namespace tflite::ops::micro;

namespace {

constexpr int kTensorArenaSize = 2096;

#if defined(EI_CLASSIFIER_ALLOCATION_STATIC)
uint8_t tensor_arena[kTensorArenaSize] ALIGN(16);
#elif defined(EI_CLASSIFIER_ALLOCATION_STATIC_HIMAX)
#pragma Bss(".tensor_arena")
uint8_t tensor_arena[kTensorArenaSize] ALIGN(16);
#pragma Bss()
#elif defined(EI_CLASSIFIER_ALLOCATION_STATIC_HIMAX_GNU)
uint8_t tensor_arena[kTensorArenaSize] ALIGN(16) __attribute__((section(".tensor_arena")));
#else
#define EI_CLASSIFIER_ALLOCATION_HEAP 1
uint8_t* tensor_arena = NULL;
#endif

static uint8_t* tensor_boundary;
static uint8_t* current_location;

template <int SZ, class T> struct TfArray {
  int sz; T elem[SZ];
};
enum used_operators_e {
  OP_RESHAPE, OP_CONV_2D, OP_MAX_POOL_2D, OP_FULLY_CONNECTED, OP_SOFTMAX,  OP_LAST
};
struct TensorInfo_t { // subset of TfLiteTensor used for initialization from constant memory
  TfLiteAllocationType allocation_type;
  TfLiteType type;
  void* data;
  TfLiteIntArray* dims;
  size_t bytes;
  TfLiteQuantization quantization;
};
struct NodeInfo_t { // subset of TfLiteNode used for initialization from constant memory
  struct TfLiteIntArray* inputs;
  struct TfLiteIntArray* outputs;
  void* builtin_data;
  used_operators_e used_op_index;
};

TfLiteContext ctx{};
TfLiteTensor tflTensors[23];
TfLiteEvalTensor tflEvalTensors[23];
TfLiteRegistration registrations[OP_LAST];
TfLiteNode tflNodes[11];

const TfArray<2, int> tensor_dimension0 = { 2, { 1,650 } };
const TfArray<1, float> quant0_scale = { 1, { 0.044819656759500504, } };
const TfArray<1, int> quant0_zero = { 1, { -12 } };
const TfLiteAffineQuantization quant0 = { (TfLiteFloatArray*)&quant0_scale, (TfLiteIntArray*)&quant0_zero, 0 };
const ALIGN(16) int32_t tensor_data1[4] = { 1, 1, 50, 13, };
const TfArray<1, int> tensor_dimension1 = { 1, { 4 } };
const ALIGN(16) int32_t tensor_data2[4] = { 1, 50, 1, 8, };
const TfArray<1, int> tensor_dimension2 = { 1, { 4 } };
const ALIGN(16) int32_t tensor_data3[4] = { 1, 1, 25, 8, };
const TfArray<1, int> tensor_dimension3 = { 1, { 4 } };
const ALIGN(16) int32_t tensor_data4[4] = { 1, 25, 1, 16, };
const TfArray<1, int> tensor_dimension4 = { 1, { 4 } };
const ALIGN(8) int32_t tensor_data5[2] = { -1, 208, };
const TfArray<1, int> tensor_dimension5 = { 1, { 2 } };
const ALIGN(16) int8_t tensor_data6[8*1*3*13] = { 
  /* [0][0][][] */ -43,44,37,-8,0,8,6,-4,10,15,-5,7,1, 127,-62,-60,18,-10,-18,-24,-9,10,6,-1,15,7, -62,24,42,2,5,23,10,-6,10,3,9,6,1, 
  /* [1][0][][] */ -127,-110,-39,-44,29,13,-76,-7,5,67,-15,-88,-6, -90,-29,-16,17,45,-57,-75,27,88,38,-15,28,19, -107,-82,-11,58,27,19,-7,12,-5,-19,-14,-24,0, 
  /* [2][0][][] */ -2,-27,-7,57,-127,-18,-80,-23,14,-25,-24,67,-13, -16,-13,-29,-6,-29,-40,6,-32,28,-29,39,19,-27, -45,-43,9,17,7,-26,-32,-35,5,16,2,19,19, 
  /* [3][0][][] */ 127,47,-93,30,4,-24,7,26,-20,50,-26,17,17, 105,92,-45,-9,20,37,-29,-64,0,22,11,-18,-32, 101,120,-74,-55,-1,43,-36,-42,6,-12,-9,48,-34, 
  /* [4][0][][] */ 21,21,-43,10,77,-8,17,37,57,-16,14,37,-24, 49,16,-127,-12,-123,-60,-32,-25,22,-54,-25,-30,-51, -39,-23,119,43,-26,-5,26,62,-6,22,60,21,-66, 
  /* [5][0][][] */ 40,37,26,36,63,-38,-31,-42,49,-80,116,-31,-34, -71,8,79,127,-28,87,-65,21,8,-49,54,-30,4, -41,-38,83,94,23,56,-66,45,16,-81,64,-2,-42, 
  /* [6][0][][] */ -117,-110,-82,-17,2,44,61,42,-56,18,-10,25,5, -41,59,-8,22,54,-11,-48,-63,52,24,22,-4,-10, -18,58,73,-127,-93,-34,-7,42,65,56,-34,-3,-4, 
  /* [7][0][][] */ -26,-35,104,25,17,-34,-37,-121,-3,67,-74,-27,69, 127,-54,49,-10,-29,-5,-39,-31,-5,109,-87,-11,24, -17,-76,124,-14,-58,-87,29,-121,7,21,28,-80,120, 
};
const TfArray<4, int> tensor_dimension6 = { 4, { 8,1,3,13 } };
const TfArray<8, float> quant6_scale = { 8, { 0.010366463102400303, 0.0048136836849153042, 0.0071740290150046349, 0.0050006154924631119, 0.0049194814637303352, 0.0038944587577134371, 0.0049579506739974022, 0.0037340922281146049, } };
const TfArray<8, int> quant6_zero = { 8, { 0,0,0,0,0,0,0,0 } };
const TfLiteAffineQuantization quant6 = { (TfLiteFloatArray*)&quant6_scale, (TfLiteIntArray*)&quant6_zero, 0 };
const ALIGN(16) int32_t tensor_data7[8] = { -1258, 1275, -830, -3084, -2323, -3482, -1171, -5245, };
const TfArray<1, int> tensor_dimension7 = { 1, { 8 } };
const TfArray<8, float> quant7_scale = { 8, { 0.00046462132013402879, 0.00021574765560217202, 0.00032153751817531884, 0.00022412587713915855, 0.0002204894699389115, 0.00017454830231145024, 0.00022221365361474454, 0.00016736073303036392, } };
const TfArray<8, int> quant7_zero = { 8, { 0,0,0,0,0,0,0,0 } };
const TfLiteAffineQuantization quant7 = { (TfLiteFloatArray*)&quant7_scale, (TfLiteIntArray*)&quant7_zero, 0 };
const ALIGN(16) int8_t tensor_data8[16*1*3*8] = { 
  /* [0][0][][] */ -47,6,-100,38,-10,-91,26,-77, 21,-30,-74,0,9,-127,5,-24, -12,-53,-3,79,20,-60,48,14, 
  /* [1][0][][] */ -38,7,-41,-127,-44,-6,16,9, -38,-16,-32,-84,-91,10,6,4, -23,39,-23,16,-82,-26,0,9, 
  /* [2][0][][] */ -41,16,-82,-22,-27,77,-4,-55, 30,16,-73,-34,-21,-46,-10,-34, -33,4,-127,-35,22,-72,51,-93, 
  /* [3][0][][] */ -76,-10,-24,-89,-127,65,-82,60, -46,68,9,-71,-24,70,3,26, -38,-3,26,-79,-58,65,-8,-12, 
  /* [4][0][][] */ 71,-50,23,-112,-32,-72,-10,75, 20,-100,79,-88,-53,-81,-92,9, 65,-74,29,-31,-95,-5,-127,106, 
  /* [5][0][][] */ 12,-97,40,21,-1,62,-84,40, -17,-127,17,17,-10,-4,-123,-12, -16,-96,-9,9,18,29,-87,-20, 
  /* [6][0][][] */ 31,-80,50,59,28,7,-127,-40, 5,-78,5,-11,23,52,-79,-35, -67,-77,-55,-13,61,-40,-51,-53, 
  /* [7][0][][] */ -30,-43,-3,-2,19,30,-54,-31, -67,-66,-57,1,39,10,-74,-127, -60,-92,-107,-8,19,79,-95,-41, 
  /* [8][0][][] */ 20,-127,12,-13,0,17,-59,47, 16,-106,-10,-45,-8,-1,-34,-30, 11,-31,-12,-76,-9,-17,-28,71, 
  /* [9][0][][] */ -79,5,26,-127,15,-1,6,-64, -82,49,18,-115,-2,-29,-16,-16, -99,6,11,-109,-30,-21,-18,-24, 
  /* [10][0][][] */ -3,7,-17,-9,36,-12,5,-46, 127,-13,49,46,114,-64,2,-19, 7,-8,-28,0,-16,-60,46,-41, 
  /* [11][0][][] */ -29,-23,-82,103,-57,-74,-23,64, -69,66,-127,-47,-58,-107,-37,72, -49,3,-96,75,2,-53,-36,15, 
  /* [12][0][][] */ 71,-35,-54,-15,82,-9,7,-44, -92,4,73,-31,127,-3,73,-31, 72,60,-18,-56,-5,14,47,-28, 
  /* [13][0][][] */ -8,-16,-26,86,-17,-14,-71,-106, -16,-66,-46,-16,-14,-3,-79,-12, -33,-127,-90,17,-12,-15,-47,24, 
  /* [14][0][][] */ 12,-37,46,23,-29,75,-92,-102, -45,8,-47,-6,-2,-31,-28,-127, -85,15,-24,-20,18,52,-54,-82, 
  /* [15][0][][] */ 116,-30,-18,-14,-4,15,7,-34, -28,-41,3,-1,29,21,32,-17, 127,-22,39,-10,-26,-21,-34,26, 
};
const TfArray<4, int> tensor_dimension8 = { 4, { 16,1,3,8 } };
const TfArray<16, float> quant8_scale = { 16, { 0.0060694925487041473, 0.0076235146261751652, 0.0067835454829037189, 0.0039616883732378483, 0.0041647381149232388, 0.0077384463511407375, 0.005829228088259697, 0.0073113441467285156, 0.0078081297688186169, 0.0064676506444811821, 0.0043879086151719093, 0.0042481515556573868, 0.0036594744306057692, 0.0059583527036011219, 0.005847616121172905, 0.005063655786216259, } };
const TfArray<16, int> quant8_zero = { 16, { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 } };
const TfLiteAffineQuantization quant8 = { (TfLiteFloatArray*)&quant8_scale, (TfLiteIntArray*)&quant8_zero, 0 };
const ALIGN(16) int32_t tensor_data9[16] = { -816, 1763, 567, -1380, -2338, -2073, -1234, -185, -106, 202, -1874, -1253, -2440, -438, -1380, -1113, };
const TfArray<1, int> tensor_dimension9 = { 1, { 16 } };
const TfArray<16, float> quant9_scale = { 16, { 0.00023774485453031957, 0.00029861662187613547, 0.00026571465423330665, 0.00015518118743784726, 0.00016313474043272436, 0.00030311854789033532, 0.00022833357797935605, 0.00028638876392506063, 0.00030584807973355055, 0.0002533408987801522, 0.00017187642515636981, 0.00016640208195894957, 0.00014334332081489265, 0.00023339145991485566, 0.00022905385412741452, 0.00019834576232824475, } };
const TfArray<16, int> quant9_zero = { 16, { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 } };
const TfLiteAffineQuantization quant9 = { (TfLiteFloatArray*)&quant9_scale, (TfLiteIntArray*)&quant9_zero, 0 };
const ALIGN(16) int8_t tensor_data10[4*208] = { 
  -87, 4, -62, -14, 1, -24, -11, 58, 25, 44, -54, -62, -15, -1, 22, -39, 12, -9, -58, -14, 36, 21, -21, 41, 60, 42, -7, -58, -22, -24, -44, 48, 7, -25, -6, -7, 28, 20, -26, 23, 45, 30, -19, -27, -37, -127, -25, 9, -34, -23, -22, 5, 26, 23, -23, 14, 58, 34, -40, -46, -5, -77, -21, 17, -37, -8, 16, -16, 36, -2, -27, 17, 52, 9, -52, -29, -35, -113, -14, 19, 26, 2, -28, 21, 13, -19, -29, 19, 68, -38, -2, -15, -9, -28, -19, 10, 19, -61, -32, -16, 39, -6, -39, -37, 46, -56, -4, 11, -71, -2, -26, 3, 7, -31, -36, -14, 29, 4, -18, -6, 45, -53, -27, 7, -46, -17, 30, 14, 37, -30, -5, 35, 16, -22, -48, -60, 54, 16, -11, 20, -9, -22, 7, 4, 24, -15, -77, -12, 22, 5, -22, -12, 45, 28, -10, 27, -8, 16, 8, -16, 27, -33, 4, 15, 1, -37, -2, 19, 19, 36, 4, 30, -30, 28, 3, -53, 48, -18, -46, -5, -40, -13, -14, 35, -23, 40, 29, 17, 7, 10, -25, -1, 26, -48, -72, -24, -14, 27, 7, 21, 0, 54, 0, 18, 28, 13, 67, 15, 
  -55, 1, 5, -27, 10, -48, -49, -52, -22, 0, -27, -15, -22, -47, -81, -15, -52, 11, -12, -35, 19, 51, -29, 31, -45, -2, -23, 19, -23, -34, -14, -56, -43, 12, 13, -16, 0, 13, 44, 3, -37, -7, -17, 16, -18, 34, 32, -19, -28, 27, 26, -17, 22, 35, 19, 35, -51, -16, -21, -11, 2, 32, 28, -22, -35, 35, 8, -11, 23, 41, 31, 22, -15, 19, -7, -27, 9, -5, 37, -19, -51, 29, 22, 1, 0, 47, 22, 26, -22, 20, -36, -12, -20, 19, 32, -19, -58, 27, 42, -25, 1, 48, 45, 47, -34, 29, -31, -24, -24, 0, 42, -18, -43, 41, 66, 14, 17, 22, 26, 43, -31, -6, -25, -24, 5, 6, 47, -13, -43, 17, 64, -27, -5, 19, 15, 33, -47, -11, 1, -23, 16, 3, 27, -23, -19, 2, 43, -22, -5, 38, 27, 33, -67, -15, -13, -29, -24, 20, 32, -17, -38, 22, 43, -54, -60, 26, 52, 28, -39, -15, -11, -47, -9, 18, 6, 19, -20, 9, 35, -13, -51, 31, 30, 44, -7, -20, -32, -33, -14, -9, 31, 3, -50, 33, 43, 15, -34, -21, 19, 48, 0, -15, -50, -30, -16, -16, 14, 22, 
  41, -22, 24, 23, 2, 88, 61, -20, -4, -38, 53, 3, 11, -24, -13, 45, 26, -15, -10, -1, -21, 27, 21, -13, 12, -30, 31, 9, 19, -57, 36, 40, 7, -54, -17, 12, -29, -34, -46, -13, -11, -23, 29, 0, 17, -49, 1, 26, 25, 4, -55, 7, -9, -47, -28, -16, -21, -22, 12, 8, 33, -41, -27, 20, 12, -21, 9, 29, -6, -46, -31, -31, -46, -18, 15, 7, 39, -4, 5, 6, 1, -4, 41, 20, -16, -38, -6, -43, -26, -19, 5, -24, 41, -2, -2, 3, 3, -60, -14, -4, -24, -38, -10, -46, -4, -8, 10, -8, 35, -20, 2, 11, 6, 21, 21, -33, -16, -43, -22, 15, -32, 7, 9, -20, 28, -35, -13, -15, 7, 17, 7, 16, -21, -62, 3, -37, -19, -36, -11, -11, -20, -13, -55, 17, -6, -8, -2, 40, -5, -35, -38, 4, -5, -22, 11, -9, 18, -67, -4, 12, 4, -34, -41, 21, -7, -21, -43, -11, -13, -7, 17, 0, 6, -29, -27, 13, 15, -37, -8, -8, 62, -27, -13, 12, 32, -45, 15, 18, 13, -20, -44, 72, 46, -25, 4, -12, 53, 10, 22, 5, 38, -28, 61, 17, 13, 0, -41, 43, 
  6, 16, 23, 26, 1, -33, -25, -13, -1, 21, -1, 26, -11, 40, 53, 21, 10, 2, 27, 29, -15, -25, -15, -6, -4, 16, -10, 25, 1, 91, -23, -19, 24, 7, -12, 28, -27, -4, 11, -20, -5, 12, -22, 16, -14, 28, -5, -15, 40, 12, 45, 23, -10, -8, -11, -24, -7, 6, -8, 41, -8, 38, -10, -13, 30, 17, -28, 5, -15, 25, 23, -8, -6, 28, 19, 25, 7, 48, -30, -25, 28, 13, -11, -4, -49, 4, -5, -1, 5, 40, -9, 51, -11, 19, -4, -7, 21, 32, -7, 21, -6, 6, 3, 24, 2, 7, -10, 19, 9, 2, -25, -12, 18, -4, -13, 11, -2, -3, -18, -12, -4, 51, 5, 15, 28, 6, -40, 8, 28, 21, -26, 4, -5, 4, 9, 28, 1, 1, -6, 23, -7, 14, -15, -10, 9, 23, -27, 2, -20, 21, -5, 2, -2, -8, -3, 14, -15, 16, -7, -8, 25, 22, 0, 13, 23, -6, 13, -48, 4, 10, -6, 18, -10, 32, -7, -6, 13, 18, -3, 16, -6, 29, -9, -78, -27, 4, -20, 4, -14, 6, -3, -29, -38, 45, 35, 10, -12, -3, -7, -39, 4, 26, -35, -3, -23, -40, -14, -53, 
};
const TfArray<2, int> tensor_dimension10 = { 2, { 4,208 } };
const TfArray<1, float> quant10_scale = { 1, { 0.0081324959173798561, } };
const TfArray<1, int> quant10_zero = { 1, { 0 } };
const TfLiteAffineQuantization quant10 = { (TfLiteFloatArray*)&quant10_scale, (TfLiteIntArray*)&quant10_zero, 0 };
const ALIGN(16) int32_t tensor_data11[4] = { -964, -1025, 733, 719, };
const TfArray<1, int> tensor_dimension11 = { 1, { 4 } };
const TfArray<1, float> quant11_scale = { 1, { 0.00027179971220903099, } };
const TfArray<1, int> quant11_zero = { 1, { 0 } };
const TfLiteAffineQuantization quant11 = { (TfLiteFloatArray*)&quant11_scale, (TfLiteIntArray*)&quant11_zero, 0 };
const TfArray<4, int> tensor_dimension12 = { 4, { 1,1,50,13 } };
const TfArray<1, float> quant12_scale = { 1, { 0.044819656759500504, } };
const TfArray<1, int> quant12_zero = { 1, { -12 } };
const TfLiteAffineQuantization quant12 = { (TfLiteFloatArray*)&quant12_scale, (TfLiteIntArray*)&quant12_zero, 0 };
const TfArray<4, int> tensor_dimension13 = { 4, { 1,1,50,8 } };
const TfArray<1, float> quant13_scale = { 1, { 0.039170466363430023, } };
const TfArray<1, int> quant13_zero = { 1, { -128 } };
const TfLiteAffineQuantization quant13 = { (TfLiteFloatArray*)&quant13_scale, (TfLiteIntArray*)&quant13_zero, 0 };
const TfArray<4, int> tensor_dimension14 = { 4, { 1,50,1,8 } };
const TfArray<1, float> quant14_scale = { 1, { 0.039170466363430023, } };
const TfArray<1, int> quant14_zero = { 1, { -128 } };
const TfLiteAffineQuantization quant14 = { (TfLiteFloatArray*)&quant14_scale, (TfLiteIntArray*)&quant14_zero, 0 };
const TfArray<4, int> tensor_dimension15 = { 4, { 1,25,1,8 } };
const TfArray<1, float> quant15_scale = { 1, { 0.039170466363430023, } };
const TfArray<1, int> quant15_zero = { 1, { -128 } };
const TfLiteAffineQuantization quant15 = { (TfLiteFloatArray*)&quant15_scale, (TfLiteIntArray*)&quant15_zero, 0 };
const TfArray<4, int> tensor_dimension16 = { 4, { 1,1,25,8 } };
const TfArray<1, float> quant16_scale = { 1, { 0.039170466363430023, } };
const TfArray<1, int> quant16_zero = { 1, { -128 } };
const TfLiteAffineQuantization quant16 = { (TfLiteFloatArray*)&quant16_scale, (TfLiteIntArray*)&quant16_zero, 0 };
const TfArray<4, int> tensor_dimension17 = { 4, { 1,1,25,16 } };
const TfArray<1, float> quant17_scale = { 1, { 0.033421438187360764, } };
const TfArray<1, int> quant17_zero = { 1, { -128 } };
const TfLiteAffineQuantization quant17 = { (TfLiteFloatArray*)&quant17_scale, (TfLiteIntArray*)&quant17_zero, 0 };
const TfArray<4, int> tensor_dimension18 = { 4, { 1,25,1,16 } };
const TfArray<1, float> quant18_scale = { 1, { 0.033421438187360764, } };
const TfArray<1, int> quant18_zero = { 1, { -128 } };
const TfLiteAffineQuantization quant18 = { (TfLiteFloatArray*)&quant18_scale, (TfLiteIntArray*)&quant18_zero, 0 };
const TfArray<4, int> tensor_dimension19 = { 4, { 1,13,1,16 } };
const TfArray<1, float> quant19_scale = { 1, { 0.033421438187360764, } };
const TfArray<1, int> quant19_zero = { 1, { -128 } };
const TfLiteAffineQuantization quant19 = { (TfLiteFloatArray*)&quant19_scale, (TfLiteIntArray*)&quant19_zero, 0 };
const TfArray<2, int> tensor_dimension20 = { 2, { 1,208 } };
const TfArray<1, float> quant20_scale = { 1, { 0.033421438187360764, } };
const TfArray<1, int> quant20_zero = { 1, { -128 } };
const TfLiteAffineQuantization quant20 = { (TfLiteFloatArray*)&quant20_scale, (TfLiteIntArray*)&quant20_zero, 0 };
const TfArray<2, int> tensor_dimension21 = { 2, { 1,4 } };
const TfArray<1, float> quant21_scale = { 1, { 0.098205149173736572, } };
const TfArray<1, int> quant21_zero = { 1, { -6 } };
const TfLiteAffineQuantization quant21 = { (TfLiteFloatArray*)&quant21_scale, (TfLiteIntArray*)&quant21_zero, 0 };
const TfArray<2, int> tensor_dimension22 = { 2, { 1,4 } };
const TfArray<1, float> quant22_scale = { 1, { 0.00390625, } };
const TfArray<1, int> quant22_zero = { 1, { -128 } };
const TfLiteAffineQuantization quant22 = { (TfLiteFloatArray*)&quant22_scale, (TfLiteIntArray*)&quant22_zero, 0 };
const TfLiteReshapeParams opdata0 = { { 0, 0, 0, 0, 0, 0, 0, 0, }, 0 };
const TfArray<2, int> inputs0 = { 2, { 0,1 } };
const TfArray<1, int> outputs0 = { 1, { 12 } };
const TfLiteConvParams opdata1 = { kTfLitePaddingSame, 1,1, kTfLiteActRelu, 1,1 };
const TfArray<3, int> inputs1 = { 3, { 12,6,7 } };
const TfArray<1, int> outputs1 = { 1, { 13 } };
const TfLiteReshapeParams opdata2 = { { 0, 0, 0, 0, 0, 0, 0, 0, }, 0 };
const TfArray<2, int> inputs2 = { 2, { 13,2 } };
const TfArray<1, int> outputs2 = { 1, { 14 } };
const TfLitePoolParams opdata3 = { kTfLitePaddingSame, 1,2, 1,2, kTfLiteActNone, { { 0,0, 0, 0 } } };
const TfArray<1, int> inputs3 = { 1, { 14 } };
const TfArray<1, int> outputs3 = { 1, { 15 } };
const TfLiteReshapeParams opdata4 = { { 0, 0, 0, 0, 0, 0, 0, 0, }, 0 };
const TfArray<2, int> inputs4 = { 2, { 15,3 } };
const TfArray<1, int> outputs4 = { 1, { 16 } };
const TfLiteConvParams opdata5 = { kTfLitePaddingSame, 1,1, kTfLiteActRelu, 1,1 };
const TfArray<3, int> inputs5 = { 3, { 16,8,9 } };
const TfArray<1, int> outputs5 = { 1, { 17 } };
const TfLiteReshapeParams opdata6 = { { 0, 0, 0, 0, 0, 0, 0, 0, }, 0 };
const TfArray<2, int> inputs6 = { 2, { 17,4 } };
const TfArray<1, int> outputs6 = { 1, { 18 } };
const TfLitePoolParams opdata7 = { kTfLitePaddingSame, 1,2, 1,2, kTfLiteActNone, { { 0,0, 0, 0 } } };
const TfArray<1, int> inputs7 = { 1, { 18 } };
const TfArray<1, int> outputs7 = { 1, { 19 } };
const TfLiteReshapeParams opdata8 = { { 0, 0, 0, 0, 0, 0, 0, 0, }, 0 };
const TfArray<2, int> inputs8 = { 2, { 19,5 } };
const TfArray<1, int> outputs8 = { 1, { 20 } };
const TfLiteFullyConnectedParams opdata9 = { kTfLiteActNone, kTfLiteFullyConnectedWeightsFormatDefault, false, false };
const TfArray<3, int> inputs9 = { 3, { 20,10,11 } };
const TfArray<1, int> outputs9 = { 1, { 21 } };
const TfLiteSoftmaxParams opdata10 = { 1 };
const TfArray<1, int> inputs10 = { 1, { 21 } };
const TfArray<1, int> outputs10 = { 1, { 22 } };
const TensorInfo_t tensorData[] = {
  { kTfLiteArenaRw, kTfLiteInt8, tensor_arena + 656, (TfLiteIntArray*)&tensor_dimension0, 650, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant0))}, },
  { kTfLiteMmapRo, kTfLiteInt32, (void*)tensor_data1, (TfLiteIntArray*)&tensor_dimension1, 16, {kTfLiteNoQuantization, nullptr}, },
  { kTfLiteMmapRo, kTfLiteInt32, (void*)tensor_data2, (TfLiteIntArray*)&tensor_dimension2, 16, {kTfLiteNoQuantization, nullptr}, },
  { kTfLiteMmapRo, kTfLiteInt32, (void*)tensor_data3, (TfLiteIntArray*)&tensor_dimension3, 16, {kTfLiteNoQuantization, nullptr}, },
  { kTfLiteMmapRo, kTfLiteInt32, (void*)tensor_data4, (TfLiteIntArray*)&tensor_dimension4, 16, {kTfLiteNoQuantization, nullptr}, },
  { kTfLiteMmapRo, kTfLiteInt32, (void*)tensor_data5, (TfLiteIntArray*)&tensor_dimension5, 8, {kTfLiteNoQuantization, nullptr}, },
  { kTfLiteMmapRo, kTfLiteInt8, (void*)tensor_data6, (TfLiteIntArray*)&tensor_dimension6, 312, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant6))}, },
  { kTfLiteMmapRo, kTfLiteInt32, (void*)tensor_data7, (TfLiteIntArray*)&tensor_dimension7, 32, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant7))}, },
  { kTfLiteMmapRo, kTfLiteInt8, (void*)tensor_data8, (TfLiteIntArray*)&tensor_dimension8, 384, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant8))}, },
  { kTfLiteMmapRo, kTfLiteInt32, (void*)tensor_data9, (TfLiteIntArray*)&tensor_dimension9, 64, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant9))}, },
  { kTfLiteMmapRo, kTfLiteInt8, (void*)tensor_data10, (TfLiteIntArray*)&tensor_dimension10, 832, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant10))}, },
  { kTfLiteMmapRo, kTfLiteInt32, (void*)tensor_data11, (TfLiteIntArray*)&tensor_dimension11, 16, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant11))}, },
  { kTfLiteArenaRw, kTfLiteInt8, tensor_arena + 0, (TfLiteIntArray*)&tensor_dimension12, 650, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant12))}, },
  { kTfLiteArenaRw, kTfLiteInt8, tensor_arena + 656, (TfLiteIntArray*)&tensor_dimension13, 400, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant13))}, },
  { kTfLiteArenaRw, kTfLiteInt8, tensor_arena + 0, (TfLiteIntArray*)&tensor_dimension14, 400, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant14))}, },
  { kTfLiteArenaRw, kTfLiteInt8, tensor_arena + 400, (TfLiteIntArray*)&tensor_dimension15, 200, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant15))}, },
  { kTfLiteArenaRw, kTfLiteInt8, tensor_arena + 0, (TfLiteIntArray*)&tensor_dimension16, 200, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant16))}, },
  { kTfLiteArenaRw, kTfLiteInt8, tensor_arena + 400, (TfLiteIntArray*)&tensor_dimension17, 400, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant17))}, },
  { kTfLiteArenaRw, kTfLiteInt8, tensor_arena + 0, (TfLiteIntArray*)&tensor_dimension18, 400, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant18))}, },
  { kTfLiteArenaRw, kTfLiteInt8, tensor_arena + 400, (TfLiteIntArray*)&tensor_dimension19, 208, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant19))}, },
  { kTfLiteArenaRw, kTfLiteInt8, tensor_arena + 0, (TfLiteIntArray*)&tensor_dimension20, 208, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant20))}, },
  { kTfLiteArenaRw, kTfLiteInt8, tensor_arena + 208, (TfLiteIntArray*)&tensor_dimension21, 4, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant21))}, },
  { kTfLiteArenaRw, kTfLiteInt8, tensor_arena + 0, (TfLiteIntArray*)&tensor_dimension22, 4, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant22))}, },
};const NodeInfo_t nodeData[] = {
  { (TfLiteIntArray*)&inputs0, (TfLiteIntArray*)&outputs0, const_cast<void*>(static_cast<const void*>(&opdata0)), OP_RESHAPE, },
  { (TfLiteIntArray*)&inputs1, (TfLiteIntArray*)&outputs1, const_cast<void*>(static_cast<const void*>(&opdata1)), OP_CONV_2D, },
  { (TfLiteIntArray*)&inputs2, (TfLiteIntArray*)&outputs2, const_cast<void*>(static_cast<const void*>(&opdata2)), OP_RESHAPE, },
  { (TfLiteIntArray*)&inputs3, (TfLiteIntArray*)&outputs3, const_cast<void*>(static_cast<const void*>(&opdata3)), OP_MAX_POOL_2D, },
  { (TfLiteIntArray*)&inputs4, (TfLiteIntArray*)&outputs4, const_cast<void*>(static_cast<const void*>(&opdata4)), OP_RESHAPE, },
  { (TfLiteIntArray*)&inputs5, (TfLiteIntArray*)&outputs5, const_cast<void*>(static_cast<const void*>(&opdata5)), OP_CONV_2D, },
  { (TfLiteIntArray*)&inputs6, (TfLiteIntArray*)&outputs6, const_cast<void*>(static_cast<const void*>(&opdata6)), OP_RESHAPE, },
  { (TfLiteIntArray*)&inputs7, (TfLiteIntArray*)&outputs7, const_cast<void*>(static_cast<const void*>(&opdata7)), OP_MAX_POOL_2D, },
  { (TfLiteIntArray*)&inputs8, (TfLiteIntArray*)&outputs8, const_cast<void*>(static_cast<const void*>(&opdata8)), OP_RESHAPE, },
  { (TfLiteIntArray*)&inputs9, (TfLiteIntArray*)&outputs9, const_cast<void*>(static_cast<const void*>(&opdata9)), OP_FULLY_CONNECTED, },
  { (TfLiteIntArray*)&inputs10, (TfLiteIntArray*)&outputs10, const_cast<void*>(static_cast<const void*>(&opdata10)), OP_SOFTMAX, },
};
static std::vector<void*> overflow_buffers;
static void * AllocatePersistentBuffer(struct TfLiteContext* ctx,
                                       size_t bytes) {
  void *ptr;
  if (current_location - bytes < tensor_boundary) {
    // OK, this will look super weird, but.... we have CMSIS-NN buffers which
    // we cannot calculate beforehand easily.
    ptr = ei_calloc(bytes, 1);
    if (ptr == NULL) {
      printf("ERR: Failed to allocate persistent buffer of size %d\n", (int)bytes);
      return NULL;
    }
    overflow_buffers.push_back(ptr);
    return ptr;
  }

  current_location -= bytes;

  ptr = current_location;
  memset(ptr, 0, bytes);

  return ptr;
}
typedef struct {
  size_t bytes;
  void *ptr;
} scratch_buffer_t;
static std::vector<scratch_buffer_t> scratch_buffers;

static TfLiteStatus RequestScratchBufferInArena(struct TfLiteContext* ctx, size_t bytes,
                                                int* buffer_idx) {
  scratch_buffer_t b;
  b.bytes = bytes;

  b.ptr = AllocatePersistentBuffer(ctx, b.bytes);
  if (!b.ptr) {
    return kTfLiteError;
  }

  scratch_buffers.push_back(b);

  *buffer_idx = scratch_buffers.size() - 1;

  return kTfLiteOk;
}

static void* GetScratchBuffer(struct TfLiteContext* ctx, int buffer_idx) {
  if (buffer_idx > static_cast<int>(scratch_buffers.size()) - 1) {
    return NULL;
  }
  return scratch_buffers[buffer_idx].ptr;
}

static TfLiteTensor* GetTensor(const struct TfLiteContext* context,
                               int tensor_idx) {
  return &tflTensors[tensor_idx];
}

static TfLiteEvalTensor* GetEvalTensor(const struct TfLiteContext* context,
                                       int tensor_idx) {
  return &tflEvalTensors[tensor_idx];
}

} // namespace

TfLiteStatus trained_model_init( void*(*alloc_fnc)(size_t,size_t) ) {
#ifdef EI_CLASSIFIER_ALLOCATION_HEAP
  tensor_arena = (uint8_t*) alloc_fnc(16, kTensorArenaSize);
  if (!tensor_arena) {
    printf("ERR: failed to allocate tensor arena\n");
    return kTfLiteError;
  }
#else
  memset(tensor_arena, 0, kTensorArenaSize);
#endif
  tensor_boundary = tensor_arena;
  current_location = tensor_arena + kTensorArenaSize;
  ctx.AllocatePersistentBuffer = &AllocatePersistentBuffer;
  ctx.RequestScratchBufferInArena = &RequestScratchBufferInArena;
  ctx.GetScratchBuffer = &GetScratchBuffer;
  ctx.GetTensor = &GetTensor;
  ctx.GetEvalTensor = &GetEvalTensor;
  ctx.tensors = tflTensors;
  ctx.tensors_size = 23;
  for(size_t i = 0; i < 23; ++i) {
    tflTensors[i].type = tensorData[i].type;
    tflEvalTensors[i].type = tensorData[i].type;
    tflTensors[i].is_variable = 0;

#if defined(EI_CLASSIFIER_ALLOCATION_HEAP)
    tflTensors[i].allocation_type = tensorData[i].allocation_type;
#else
    tflTensors[i].allocation_type = (tensor_arena <= tensorData[i].data && tensorData[i].data < tensor_arena + kTensorArenaSize) ? kTfLiteArenaRw : kTfLiteMmapRo;
#endif
    tflTensors[i].bytes = tensorData[i].bytes;
    tflTensors[i].dims = tensorData[i].dims;
    tflEvalTensors[i].dims = tensorData[i].dims;

#if defined(EI_CLASSIFIER_ALLOCATION_HEAP)
    if(tflTensors[i].allocation_type == kTfLiteArenaRw){
      uint8_t* start = (uint8_t*) ((uintptr_t)tensorData[i].data + (uintptr_t) tensor_arena);

     tflTensors[i].data.data =  start;
     tflEvalTensors[i].data.data =  start;
    }
    else{
       tflTensors[i].data.data = tensorData[i].data;
       tflEvalTensors[i].data.data = tensorData[i].data;
    }
#else
    tflTensors[i].data.data = tensorData[i].data;
    tflEvalTensors[i].data.data = tensorData[i].data;
#endif // EI_CLASSIFIER_ALLOCATION_HEAP
    tflTensors[i].quantization = tensorData[i].quantization;
    if (tflTensors[i].quantization.type == kTfLiteAffineQuantization) {
      TfLiteAffineQuantization const* quant = ((TfLiteAffineQuantization const*)(tensorData[i].quantization.params));
      tflTensors[i].params.scale = quant->scale->data[0];
      tflTensors[i].params.zero_point = quant->zero_point->data[0];
    }
    if (tflTensors[i].allocation_type == kTfLiteArenaRw) {
      auto data_end_ptr = (uint8_t*)tflTensors[i].data.data + tensorData[i].bytes;
      if (data_end_ptr > tensor_boundary) {
        tensor_boundary = data_end_ptr;
      }
    }
  }
  if (tensor_boundary > current_location /* end of arena size */) {
    printf("ERR: tensor arena is too small, does not fit model - even without scratch buffers\n");
    return kTfLiteError;
  }
  registrations[OP_RESHAPE] = Register_RESHAPE();
  registrations[OP_CONV_2D] = Register_CONV_2D();
  registrations[OP_MAX_POOL_2D] = Register_MAX_POOL_2D();
  registrations[OP_FULLY_CONNECTED] = Register_FULLY_CONNECTED();
  registrations[OP_SOFTMAX] = Register_SOFTMAX();

  for(size_t i = 0; i < 11; ++i) {
    tflNodes[i].inputs = nodeData[i].inputs;
    tflNodes[i].outputs = nodeData[i].outputs;
    tflNodes[i].builtin_data = nodeData[i].builtin_data;
tflNodes[i].custom_initial_data = nullptr;
      tflNodes[i].custom_initial_data_size = 0;
if (registrations[nodeData[i].used_op_index].init) {
      tflNodes[i].user_data = registrations[nodeData[i].used_op_index].init(&ctx, (const char*)tflNodes[i].builtin_data, 0);
    }
  }
  for(size_t i = 0; i < 11; ++i) {
    if (registrations[nodeData[i].used_op_index].prepare) {
      TfLiteStatus status = registrations[nodeData[i].used_op_index].prepare(&ctx, &tflNodes[i]);
      if (status != kTfLiteOk) {
        return status;
      }
    }
  }
  return kTfLiteOk;
}

static const int inTensorIndices[] = {
  0, 
};
TfLiteTensor* trained_model_input(int index) {
  return &ctx.tensors[inTensorIndices[index]];
}

static const int outTensorIndices[] = {
  22, 
};
TfLiteTensor* trained_model_output(int index) {
  return &ctx.tensors[outTensorIndices[index]];
}

TfLiteStatus trained_model_invoke() {
  for(size_t i = 0; i < 11; ++i) {
    TfLiteStatus status = registrations[nodeData[i].used_op_index].invoke(&ctx, &tflNodes[i]);

#if EI_CLASSIFIER_PRINT_STATE
    ei_printf("layer %lu\n", i);
    ei_printf("    inputs:\n");
    for (size_t ix = 0; ix < tflNodes[i].inputs->size; ix++) {
      auto d = tensorData[tflNodes[i].inputs->data[ix]];

      size_t data_ptr = (size_t)d.data;

      if (d.allocation_type == kTfLiteArenaRw) {
        data_ptr = (size_t)tensor_arena + data_ptr;
      }

      if (d.type == TfLiteType::kTfLiteInt8) {
        int8_t* data = (int8_t*)data_ptr;
        ei_printf("        %lu (%zu bytes, ptr=%p, alloc_type=%d, type=%d): ", ix, d.bytes, data, (int)d.allocation_type, (int)d.type);
        for (size_t jx = 0; jx < d.bytes; jx++) {
          ei_printf("%d ", data[jx]);
        }
      }
      else {
        float* data = (float*)data_ptr;
        ei_printf("        %lu (%zu bytes, ptr=%p, alloc_type=%d, type=%d): ", ix, d.bytes, data, (int)d.allocation_type, (int)d.type);
        for (size_t jx = 0; jx < d.bytes / 4; jx++) {
          ei_printf("%f ", data[jx]);
        }
      }
      ei_printf("\n");
    }
    ei_printf("\n");

    ei_printf("    outputs:\n");
    for (size_t ix = 0; ix < tflNodes[i].outputs->size; ix++) {
      auto d = tensorData[tflNodes[i].outputs->data[ix]];

      size_t data_ptr = (size_t)d.data;

      if (d.allocation_type == kTfLiteArenaRw) {
        data_ptr = (size_t)tensor_arena + data_ptr;
      }

      if (d.type == TfLiteType::kTfLiteInt8) {
        int8_t* data = (int8_t*)data_ptr;
        ei_printf("        %lu (%zu bytes, ptr=%p, alloc_type=%d, type=%d): ", ix, d.bytes, data, (int)d.allocation_type, (int)d.type);
        for (size_t jx = 0; jx < d.bytes; jx++) {
          ei_printf("%d ", data[jx]);
        }
      }
      else {
        float* data = (float*)data_ptr;
        ei_printf("        %lu (%zu bytes, ptr=%p, alloc_type=%d, type=%d): ", ix, d.bytes, data, (int)d.allocation_type, (int)d.type);
        for (size_t jx = 0; jx < d.bytes / 4; jx++) {
          ei_printf("%f ", data[jx]);
        }
      }
      ei_printf("\n");
    }
    ei_printf("\n");
#endif // EI_CLASSIFIER_PRINT_STATE

    if (status != kTfLiteOk) {
      return status;
    }
  }
  return kTfLiteOk;
}

TfLiteStatus trained_model_reset( void (*free_fnc)(void* ptr) ) {
#ifdef EI_CLASSIFIER_ALLOCATION_HEAP
  free_fnc(tensor_arena);
#endif
  scratch_buffers.clear();
  for (size_t ix = 0; ix < overflow_buffers.size(); ix++) {
    free(overflow_buffers[ix]);
  }
  overflow_buffers.clear();
  return kTfLiteOk;
}
