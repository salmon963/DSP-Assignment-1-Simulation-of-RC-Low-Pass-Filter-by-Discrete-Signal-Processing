# 手寫過程
![image](https://hackmd.io/_uploads/SJnb3hnbkx.png)
![image](https://hackmd.io/_uploads/rkzzh3hZkg.png)
![image](https://hackmd.io/_uploads/rJVt23n-Je.png)
![image](https://hackmd.io/_uploads/r1iz332bJg.png)
![image](https://hackmd.io/_uploads/rJ6h22nZyx.png)
![image](https://hackmd.io/_uploads/SkgA22nWyx.png)
![image](https://hackmd.io/_uploads/HkFWpnh-1e.png)
![image](https://hackmd.io/_uploads/HyhHah3byl.png)
![image](https://hackmd.io/_uploads/H17I62hZyx.png)
![image](https://hackmd.io/_uploads/BJ58622W1x.png)
![image](https://hackmd.io/_uploads/r1eP622-kx.png)
![image](https://hackmd.io/_uploads/r1Cdp22b1e.png)

# Problem Solutions

## Problem 1

若輸入信號為 $x(t) = e^{j\Omega t}$，求解輸出 $y(t)$。假設 $y(t)$ 可以表示為 $y(t) = H(\Omega)e^{j\Omega t}$，其中 $H(\Omega)$ 是 $\Omega$ 的函數，並且與 $R$ 和 $C$ 有關。$H(\Omega)$ 將會是系統的 Fourier Transform。

根據方程：

$$
x(t) = RC \cdot \frac{dy(t)}{dt} + y(t)
$$

代入 $x(t) = e^{j\Omega t}$，則有：

$$
e^{j\Omega t} = RC \cdot \frac{dy(t)}{dt} + y(t)
$$

假設 $y(t) = H(\Omega)e^{j\Omega t}$，則

$$
\frac{dy(t)}{dt} = H(\Omega) j \Omega e^{j\Omega t}
$$

代入方程得到：

$$
e^{j\Omega t} = RC \cdot H(\Omega) j \Omega e^{j\Omega t} + H(\Omega)e^{j\Omega t}
$$

將 $e^{j\Omega t}$ 消去，得到：

$$
1 = RC \cdot H(\Omega) j \Omega + H(\Omega)
$$

解出 $H(\Omega)$：

$$
H(\Omega) = \frac{1}{j\Omega RC + 1}
$$

因此，輸出 $y(t)$ 可以表示為：

$$
y(t) = H(\Omega) e^{j\Omega t} = \frac{1}{j\Omega RC + 1} e^{j\Omega t}
$$

---

## Problem 2

若輸入信號為 $x(t) = e^{j\Omega t} u(t)$，求解 $y(t)$。注意，$y(t)$ 可以被分為穩態響應和暫態響應。

總響應可以表示為：

$$
y(t) = y_s(t) + y_t(t)
$$

### Steady-State Response

穩態響應 $y_s(t)$ 可以表示為：

$$
y_s(t) = H(\Omega) e^{j\Omega t} u(t) = \frac{1}{j\Omega RC + 1} e^{j\Omega t} u(t)
$$

### Transient Response

暫態響應 $y_t(t)$ 表示為：

$$
y_t(t) = -\int_t^{\infty} h(\tau) e^{j\Omega(t - \tau)} \, d\tau
$$

令系統的脈衝響應 $h(t) = \frac{1}{RC} e^{-\frac{t}{RC}} u(t)$，則暫態響應為：

$$
y_t(t) = -\int_t^{\infty} \frac{1}{RC} e^{-\frac{\tau}{RC}} e^{j\Omega(t - \tau)} \, d\tau
$$

經過計算，得到：

$$
y(t) = \frac{1}{j\Omega RC + 1} e^{j\Omega t} u(t) + \frac{e^{j\Omega t - \frac{t}{RC}}}{j\Omega RC + 1}
$$

---

## Problem 3

已知輸入信號為 $x(t) = e^{j\Omega t}$，並且 $R = 1000 \ \Omega$，$C = \left( \frac{1}{2\pi} \times \frac{1}{400} \times \frac{1}{1000} \right)$，求 $y(t)$，其中 $\Omega = 2 \pi \cdot f$，且 $f$ 分別為 100 Hz、400 Hz 和 3000 Hz。

### 解答過程

系統的頻率響應為：

$$
H(\Omega) = \frac{1}{j\Omega RC + 1}
$$

#### 當 $f = 100$ Hz 時
1. 計算 $\Omega$：
   $$
   \Omega = 2 \pi \times 100 = 200 \pi
   $$
   
2. 代入 $H(\Omega)$ 計算：
   $$
   H(200\pi) = \frac{1}{j(200\pi) \cdot 1000 + 1} = \frac{1}{0.25j + 1}
   $$
   
3. 因此，$y(t)$ 為：
   $$
   y(t) = \frac{1}{0.25j + 1} e^{j 200\pi t}
   $$

#### 當 $f = 400$ Hz 時
1. 計算 $\Omega$：
   $$
   \Omega = 2 \pi \times 400 = 800 \pi
   $$
   
2. 代入 $H(\Omega)$ 計算：
   $$
   H(800\pi) = \frac{1}{j(800\pi) \cdot 1000 + 1} = \frac{1}{j + 1}
   $$
   
3. 因此，$y(t)$ 為：
   $$
   y(t) = \frac{1}{j + 1} e^{j 800\pi t}
   $$

#### 當 $f = 3000$ Hz 時
1. 計算 $\Omega$：
   $$
   \Omega = 2 \pi \times 3000 = 6000 \pi
   $$
   
2. 代入 $H(\Omega)$ 計算：
   $$
   H(6000\pi) = \frac{1}{j(6000\pi) \cdot 1000 + 1} = \frac{1}{2.5j + 1}
   $$
   
3. 因此，$y(t)$ 為：
   $$
   y(t) = \frac{1}{2.5j + 1} e^{j 6000\pi t}
   $$

---

## Problem 4

若輸入信號為 $x(t) = e^{j\Omega t} u(t)$，並且 $R = 1000 \ \Omega$，$C = \left( \frac{1}{2\pi} \times \frac{1}{400} \times \frac{1}{1000} \right)$，求 $y(t)$，其中 $\Omega = 2 \pi \cdot f$，且 $f$ 分別為 100 Hz、400 Hz 和 3000 Hz。

系統的響應 $y(t)$ ：
$$
y(t) = \frac{1}{j\Omega RC + 1} e^{j\Omega t} u(t) + \frac{e^{j\Omega t - \frac{t}{RC}}}{j\Omega RC + 1}
$$

#### 當 $f = 100$ Hz 時
   $$
   y(t) = \frac{1}{0.25j + 1} e^{j 200\pi t} u(t) + \frac{e^{j 200\pi t - \frac{t}{RC}}}{0.25j + 1}
   $$

#### 當 $f = 400$ Hz 時


   $$
   y(t) = \frac{1}{j + 1} e^{j 800\pi t} u(t) + \frac{e^{j 800\pi t - \frac{t}{RC}}}{j + 1}
   $$

#### 當 $f = 3000$ Hz 時

   $$
   y(t) = \frac{1}{2.5j + 1} e^{j 6000\pi t} u(t) + \frac{e^{j 6000\pi t - \frac{t}{RC}}}{2.5j + 1}
   $$

---

## Problem 5

已知輸入信號 $x[n] = \exp(j\omega n)$，請求出對應的 $y[n] = H(\omega) \exp(j\omega n)$，其中 $H(\omega)$ 是離散時間的傅立葉變換。設置三種取樣率：4000 Hz、8000 Hz、16000 Hz。


根據系統響應公式，我們有：

$$
y[n] = H(\omega) e^{j\omega n} = \frac{RC}{RC + \tau} y[n-1] + \frac{\tau}{\tau + RC} x[\tau n]
$$

將 $x[n] = e^{j\omega n}$ 代入，並將 $y[n-1]$ 展開得到：

$$
H(\omega) e^{j\omega n} = \frac{RC}{RC + \tau} H(\omega) e^{j\omega (n-1)} + \frac{\tau}{\tau + RC} e^{j\omega n}
$$

簡化得到：

$$
H(\omega) = \frac{\frac{\tau}{\tau + RC}}{1 - \frac{RC}{RC + \tau} e^{-j\omega}}
$$

所以 $y[n]$ 可以表示為：

$$
y[n] = \frac{\frac{\tau}{\tau + RC}}{1 - \frac{RC}{RC + \tau} e^{-j\omega}} e^{j\omega n}
$$

---

### 各取樣率的計算

#### 當取樣率 $f_s = 4000$ Hz 時
1. 計算 $\omega$：
   $$
   \omega = \frac{2\pi f}{4000}, \quad \tau = \frac{1}{4000}
   $$
   
2. 帶入 $H(\omega)$ 計算：
   $$
   y[n] = \frac{\frac{1}{4000}}{\frac{1}{4000} + 800\pi} \cdot \frac{1}{1 - \frac{800\pi}{\frac{1}{4000} + 800\pi} e^{-j \frac{\pi}{2000}}} e^{j \frac{\pi}{2000} n}
   $$

#### 當取樣率 $f_s = 8000$ Hz 時
1. 計算 $\omega$：
   $$
   \omega = \frac{2\pi f}{8000}, \quad \tau = \frac{1}{8000}
   $$
   
2. 帶入 $H(\omega)$ 計算：
   $$
   y[n] = \frac{\frac{1}{8000}}{\frac{1}{8000} + 800\pi} \cdot \frac{1}{1 - \frac{800\pi}{\frac{1}{8000} + 800\pi} e^{-j \frac{\pi}{4000}}} e^{j \frac{\pi}{4000} n}
   $$

#### 當取樣率 $f_s = 16000$ Hz 時
1. 計算 $\omega$：
   $$
   \omega = \frac{2\pi f}{16000}, \quad \tau = \frac{1}{16000}
   $$
   
2. 帶入 $H(\omega)$ 計算：
   $$
   y[n] = \frac{\frac{1}{16000}}{\frac{1}{16000} + 800\pi} \cdot \frac{1}{1 - \frac{800\pi}{\frac{1}{16000} + 800\pi} e^{-j \frac{\pi}{8000}}} e^{j \frac{\pi}{8000} n}
   $$

---

## Problem 6

已知輸入信號為 $x[n] = u[n] \exp(j\omega n)$，請求出對應的 $y[n]$，其中 $y[n]$ 可以表示為暫態響應和穩態響應的組合。設置三種取樣率：4000 Hz、8000 Hz、16000 Hz。


根據系統響應公式：

$$
y[n] = x[n] * h[n] = \sum_{k} h[k] x[n-k]
$$

代入 $x[n] = e^{j\omega n}$：

$$
y[n] = \sum_{k=-\infty}^{n} h[k] e^{j\omega (n-k)} = \left( \sum_{k=-\infty}^{n} h[k] e^{-j\omega k} \right) e^{j\omega n}
$$

拆解為穩態響應和暫態響應：

$$
y[n] = \left( \sum_{k=-\infty}^{\infty} h[k] e^{-j\omega k} \right) e^{j\omega n} - \left( \sum_{k=n+1}^{\infty} h[k] e^{-j\omega k} \right) e^{j\omega n}
$$

### Steady-State Response

穩態響應 $y_s[n]$：

$$
y_s[n] = \frac{\frac{\tau}{\tau + RC}}{1 - \frac{RC}{RC + \tau} e^{-j\omega}} e^{j\omega n}
$$

### Transient State

暫態響應 $y_t[n]$ 的推導步驟如下：

$$
y_t[n] = -\left( \sum_{k=n+1}^{\infty} h[k] e^{-j\omega k} \right) e^{j\omega n}
$$

代入 $h[k] = \left( \frac{RC}{RC + \tau} \right)^k u[k]$：

$$
y_t[n] = -\left( \frac{RC}{RC + \tau} \right)^{n+1} \frac{e^{-j\omega (n+1)}}{1 - \frac{RC}{RC + \tau} e^{-j\omega}} e^{j\omega n}
$$

總響應 $y[n]$ 為：

$$
y[n] = \frac{\frac{\tau}{\tau + RC}}{1 - \frac{RC}{RC + \tau} e^{-j\omega}} e^{j\omega n} - \frac{\left( \frac{RC}{RC + \tau} \right)^{n+1} e^{-j\omega} e^{j\omega n}}{1 - \frac{RC}{RC + \tau} e^{-j\omega}}
$$

---

### 各取樣率的計算

#### 當取樣率 $f_s = 4000$ Hz 時
1. 計算 $\omega$：
   $$
   \omega = \frac{2\pi f}{4000}, \quad \tau = \frac{1}{4000}
   $$
   
2. 帶入 $y[n]$ 計算：
   $$
   y[n] = \frac{\frac{1}{4000}}{\frac{1}{4000} + 800\pi} \cdot \frac{1}{1 - \frac{800\pi}{\frac{1}{4000} + 800\pi} e^{-j \frac{\pi}{2000}}} e^{j \frac{\pi}{2000} n} - \frac{\left( \frac{800\pi}{\frac{1}{4000} + 800\pi} \right)^{n+1} e^{-j \frac{\pi}{2000}} e^{j \frac{\pi}{2000} n}}{1 - \frac{800\pi}{\frac{1}{4000} + 800\pi} e^{-j \frac{\pi}{2000}}}
   $$

#### 當取樣率 $f_s = 8000$ Hz 時
1. 計算 $\omega$：
   $$
   \omega = \frac{2\pi f}{8000}, \quad \tau = \frac{1}{8000}
   $$
   
2. 帶入 $y[n]$ 計算：
   $$
   y[n] = \frac{\frac{1}{8000}}{\frac{1}{8000} + 800\pi} \cdot \frac{1}{1 - \frac{800\pi}{\frac{1}{8000} + 800\pi} e^{-j \frac{\pi}{4000}}} e^{j \frac{\pi}{4000} n} - \frac{\left( \frac{800\pi}{\frac{1}{8000} + 800\pi} \right)^{n+1} e^{-j \frac{\pi}{4000}} e^{j \frac{\pi}{4000} n}}{1 - \frac{800\pi}{\frac{1}{8000} + 800\pi} e^{-j \frac{\pi}{4000}}}
   $$

#### 當取樣率 $f_s = 16000$ Hz 時
1. 計算 $\omega$：
   $$
   \omega = \frac{2\pi f}{16000}, \quad \tau = \frac{1}{16000}
   $$
   
2. 帶入 $y[n]$ 計算：
   $$
   y[n] = \frac{\frac{1}{16000}}{\frac{1}{16000} + 800\pi} \cdot \frac{1}{1 - \frac{800\pi}{\frac{1}{16000} + 800\pi} e^{-j \frac{\pi}{8000}}} e^{j \frac{\pi}{8000} n} - \frac{\left( \frac{800\pi}{\frac{1}{16000} + 800\pi} \right)^{n+1} e^{-j \frac{\pi}{8000}} e^{j \frac{\pi}{8000} n}}{1 - \frac{800\pi}{\frac{1}{16000} + 800\pi} e^{-j \frac{\pi}{8000}}}
   $$

---




