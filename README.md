#数値計算法
<p>Numerical Calculation Method</p>
============================

##部分選択付きガウスの消去法
<blockquote>
<p>部分選択付きガウスの消去法を用いて連立1次方程式を解く。</p>
gauss_elimination_method.c
</blockquote>

##最小二乗法
<blockquote>
<p>直線 y = a0 + a1 * x の係数 a0, a1 を求める。</p>
least_squares_method.c
</blockquote>

##ルンゲ・クッタ法
<blockquote>
<p>4次のルンゲ・クッタ法で解を(解軌跡)を数値的に求める。</p>
<p>Runge-Kutta_method.c</p>
<hr>
【高階の常微分方程式】
<p>x'' - x' -2 * x = 8, x(0) = 0, x'(0) = 0</p>
<p>x = x1, x1' = x2　とおいて、変数変換する。</p>
</hr>
</blockquote>

##ニュートン法
<p>ニュートン法を用いて解を求める。</p>
Newton-Raphson_method.c
<p>初期値を入力して、2n-minima関数で最適解を求める。</p>
Newton_method.cpp

##偏微分方程式
<p>弦の振動を波動方程式と考えて解く。</p>
wave_equation.c
