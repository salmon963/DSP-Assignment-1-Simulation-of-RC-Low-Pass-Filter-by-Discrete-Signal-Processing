#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define PI 3.14159265359

// WAV 文件頭結構
typedef struct {
    char riff[4];
    int overall_size;
    char wave[4];
    char fmt_chunk_marker[4];
    int length_of_fmt;
    short format_type;
    short channels;
    int sample_rate;
    int byterate;
    short block_align;
    short bits_per_sample;
    char data_chunk_header[4];
    int data_size;
} WAV_HEADER;

// 濾波函數
void apply_filter(float *input, float *output, int num_samples, float RC, float sample_interval) {
    float alpha = sample_interval / (RC + sample_interval); // 濾波參數
    output[0] = alpha * input[0]; // 初始條件
    for (int i = 1; i < num_samples; i++) {
        output[i] = alpha * input[i] + (1.0 - alpha) * output[i - 1];
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "使用方式: %s in_fn out_fn\n", argv[0]);
        return 1;
    }

    const char *in_fn = argv[1];
    const char *out_fn = argv[2];

    // 打開輸入 WAV 文件
    FILE *in_file = fopen(in_fn, "rb");
    if (!in_file) {
        fprintf(stderr, "無法打開文件 %s\n", in_fn);
        return 1;
    }

    WAV_HEADER wav_header;
    fread(&wav_header, sizeof(WAV_HEADER), 1, in_file);

    // 驗證 WAV 文件格式
    if (strncmp(wav_header.riff, "RIFF", 4) || strncmp(wav_header.wave, "WAVE", 4)) {
        fprintf(stderr, "輸入文件不是有效的 WAV 文件。\n");
        fclose(in_file);
        return 1;
    }

    // 計算樣本數
    int num_samples = wav_header.data_size / wav_header.block_align;
    short *input_data = malloc(wav_header.data_size);
    short *output_data = malloc(wav_header.data_size);
    fread(input_data, sizeof(short), num_samples, in_file);
    fclose(in_file);

    // 提取參數
    int sample_rate = wav_header.sample_rate;
    float sample_interval = 1.0 / sample_rate;
    float RC = 1.0 / (2 * PI * 1000.0); // 假設截止頻率為 1 kHz，可調整

    // 濾波處理（每個聲道分開處理）
    for (int ch = 0; ch < wav_header.channels; ch++) {
        float *input_channel = malloc(num_samples * sizeof(float));
        float *output_channel = malloc(num_samples * sizeof(float));
        for (int i = 0; i < num_samples; i++) {
            input_channel[i] = input_data[i * wav_header.channels + ch];
        }

        apply_filter(input_channel, output_channel, num_samples, RC, sample_interval);

        free(input_channel);
        free(output_channel);
    }

    // 寫入輸出 WAV 文件
    FILE *out_file = fopen(out_fn, "wb");
    if (!out_file) {
        fprintf(stderr, "無法創建文件 %s\n", out_fn);
        free(input_data);
        free(output_data);
        return 1;
    }

    fwrite(&wav_header, sizeof(WAV_HEADER), 1, out_file);
    fwrite(output_data, sizeof(short), num_samples, out_file);
    fclose(out_file);

    free(input_data);
    free(output_data);

    printf("濾波完成，結果已儲存至 %s。\n", out_fn);
    return 0;
}
