

float fir_coeff_LP_0_1_N16[] = {
    0.0023,
    0.0051,
    0.0130,
    0.0274,
    0.0472,
    0.0688,
    0.0874,
    0.0982,
    0.0982,
    0.0874,
    0.0688,
    0.0472,
    0.0274,
    0.0130,
    0.0051,
    0.0023};

float fir_coeff_LP_0_2_N16[] = {
     -0.0033,
     -0.0046,
     -0.0039,
      0.0089,
      0.0432,
      0.0977,
      0.1560,
      0.1940,
      0.1940,
      0.1560,
      0.0977,
      0.0432,
      0.0089,
     -0.0039,
     -0.0046,
     -0.0033};

#define N_COEFF 16  // number of fir coefficents
static float fir_data_buf[N_COEFF];   //  fir data buffer
static int pos_old = N_COEFF-1, pos_new = 0;

// input vector , pIn[], output vector , pOut[]
// vector length is dataLen
// FIR filter coefficents is const data vector 
void fir_proc(float *pIn, float *pOut, int dataLen){
  float *pCoeff = 0 ;
  int nCoeff = 0;
  nCoeff = N_COEFF;//滤波器阶数
  // pCoeff = fir_coeff_LP_0_1_N16;
  pCoeff = fir_coeff_LP_0_1_N16;//该指针指向滤波器系数数组

  int idx_data = 0, idx_fir_loop = 0;//两层循环使用的计数变量

  float filter_out= 0.0, filter_in = 0.0;//暂存输入输出数据的中间变量
  // out loop , by data point
  for(idx_data = 0; idx_data < dataLen; idx_data ++){
    int pos ;
    filter_in = pIn[idx_data];
    // update position pointer
    pos_new = (pos_new == (nCoeff-1))? 0:(pos_new+1);
    pos_old = (pos_new == 0)? (nCoeff-1):(pos_new-1);
    // updata data buffer
    fir_data_buf[pos_new] = filter_in;
    filter_out = 0.0;
    pos = pos_old;
    // inner loop , by fir proc multiply
    for(idx_fir_loop = 0; idx_fir_loop < nCoeff; idx_fir_loop ++){
      float *pD = fir_data_buf, *pC = pCoeff;
      // proc form old data to new data
      filter_out = filter_out + pC[idx_fir_loop] * pD[pos];
      pos = (pos == 0)?(nCoeff-1):(pos -1);
    }
  // save filter output
  pOut[idx_data] = filter_out;
  }
}
