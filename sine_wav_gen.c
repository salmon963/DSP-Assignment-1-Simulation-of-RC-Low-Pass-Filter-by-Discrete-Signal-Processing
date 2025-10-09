#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define PI 3.14159265359


// WAV 文件頭結構
typedef struct {
    char riff[4];                // "RIFF"
    int overall_size;            // 整個文件大小 - 8
    char wave[4];                // "WAVE"
    char fmt_chunk_marker[4];    // "fmt "
    int length_of_fmt;           // 格式區塊長度
    short format_type;           // 格式類型 (PCM = 1)
    short channels;              // 通道數
    int sample_rate;             // 採樣率
    int byterate;                // 每秒位元組數
    short block_align;           // 每個採樣塊的位元組數
    short bits_per_sample;       // 每個採樣的位數
    char data_chunk_header[4];   // "data"
    int data_size;               // 音頻資料大小
} WAV_HEADER;

void generate_wav(const char *filename, int fs, int f, double L) {
    // 計算樣本數
    int num_samples = (int)(fs * L);

    // 初始化 WAV 文件頭
    WAV_HEADER wav_header;
    memcpy(wav_header.riff, "RIFF", 4);
    memcpy(wav_header.wave, "WAVE", 4);
    memcpy(wav_header.fmt_chunk_marker, "fmt ", 4);
    memcpy(wav_header.data_chunk_header, "data", 4);
    wav_header.length_of_fmt = 16;            // PCM 格式
    wav_header.format_type = 1;               // PCM 格式
    wav_header.channels = 2;                  // 雙聲道
    wav_header.sample_rate = fs;              // 採樣率
    wav_header.bits_per_sample = 16;          // 每個樣本 16 位
    wav_header.block_align = wav_header.channels * wav_header.bits_per_sample / 8;
    wav_header.byterate = fs * wav_header.block_align;
    wav_header.data_size = num_samples * wav_header.block_align;
    wav_header.overall_size = wav_header.data_size + sizeof(WAV_HEADER) - 8;

    // 打開文件寫入
    FILE *file = fopen(filename, "wb");
    if (!file) {
        fprintf(stderr, "無法打開文件 %s\n", filename);
        exit(1);
    }

    // 寫入 WAV 文件頭
    fwrite(&wav_header, sizeof(WAV_HEADER), 1, file);

    // 生成音頻數據
    for (int i = 0; i < num_samples; i++) {
        double t = (double)i / fs;
        short left_channel = (short)(32767 * sin(2 * PI * f * t));   // 正弦波
        short right_channel = (short)(32767 * cos(2 * PI * f * t));  // 餘弦波
        fwrite(&left_channel, sizeof(short), 1, file);
        fwrite(&right_channel, sizeof(short), 1, file);
    }

    fclose(file);
    printf("文件 %s 已成功生成。\n", filename);
}

int main(int argc, char *argv[]) {
    if (argc != 5) {
        fprintf(stderr, "使用方式: %s fs f L out_fn\n", argv[0]);
        fprintf(stderr, "  fs: 採樣率 (Hz)\n");
        fprintf(stderr, "  f: 頻率 (Hz)\n");
        fprintf(stderr, "  L: 持續時間 (秒)\n");
        fprintf(stderr, "  out_fn: 輸出文件名\n");
        return 1;
    }

    // 解析參數
    int fs = atoi(argv[1]);     // 採樣率
    int f = atoi(argv[2]);      // 頻率
    double L = atof(argv[3]);   // 持續時間
    const char *out_fn = argv[4];

    // 生成 WAV 文件
    generate_wav(out_fn, fs, f, L);

    return 0;
}
