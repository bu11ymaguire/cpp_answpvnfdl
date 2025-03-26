import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
from sklearn.preprocessing import MinMaxScaler

# 분기별 배송 대수 데이터 (사용자 제공)
years = [2016, 2017, 2018, 2019, 2020, 2021, 2022, 2023, 2024]
deliveries = [
    [14.8, 14.4, 24.5, 22.2],   # 2016
    [25, 22, 26.2, 29.9],       # 2017
    [30, 40.7, 83.5, 90.7],     # 2018
    [63, 95.2, 97, 112],        # 2019
    [88.4, 90.7, 139.3, 180.6], # 2020
    [184.8, 201.25, 241.3, 308.6],  # 2021
    [310.05, 254.7, 343.83, 405.28],  # 2022
    [422.88, 466.14, 435.06, 484.51],  # 2023
    [386.91, 443.96, 462.89, 496.57]   # 2024
]

# 주가 데이터 (Yahoo Finance에서 가져옴)
stock_prices = [
    47.86, 43.02, 40.34, 42.58,  # 2016: 4, 7, 10, 2017-1
    50.38, 61.20, 70.32, 63.06,  # 2017: 4, 7, 10, 2018-1
    55.88, 60.34, 66.78, 48.36,  # 2018: 4, 7, 10, 2019-1
    50.24, 41.58, 48.60, 83.76,  # 2019: 4, 7, 10, 2020-1
    100.74, 137.34, 148.74, 223.34,  # 2020: 4, 7, 10, 2021-1
    233.34, 201.58, 254.34, 333.20,  # 2021: 4, 7, 10, 2022-1
    399.93, 357.86, 265.25, 250.76,  # 2022: 4, 7, 10, 2023-1
    123.18, 261.77, 248.48, 250.22,  # 2023: 4, 7, 10, 2024-1
    176.88, 182.87, 260.46, 288.14   # 2024: 4, 7, 10, 2025-1
]

# 분기 레이블 생성
quarters = []
for year in years:
    quarters.extend([f"{year}Q1", f"{year}Q2", f"{year}Q3", f"{year}Q4"])
sales_flat = [item for sublist in deliveries for item in sublist]

# DataFrame 생성
data = pd.DataFrame({
    'Quarter': quarters,
    'Sales': sales_flat,
    'StockPrice': stock_prices
})

# 1. 상관계수 계산
correlation = data['Sales'].corr(data['StockPrice'])
print(f"주가와 배송 대수 간 상관계수: {correlation:.3f}")
if correlation > 0.7:
    print(" -> 강한 양의 상관관계")
elif correlation < -0.7:
    print(" -> 강한 음의 상관관계")
else:
    print(" -> 약한 상관관계 또는 무관")

# 2. 정규화
scaler = MinMaxScaler()
normalized = scaler.fit_transform(data[['Sales', 'StockPrice']])
data[['Sales_Norm', 'StockPrice_Norm']] = normalized

# 3. 그래프 그리기
plt.figure(figsize=(12, 6))
plt.plot(data['Quarter'], data['Sales_Norm'], label='Deliveries (Normalized)', marker='o')
plt.plot(data['Quarter'], data['StockPrice_Norm'], label='Stock Price (Normalized)', marker='o')
plt.title('Tesla Deliveries vs Stock Price (Normalized, 2016-2024)')
plt.xlabel('Quarter')
plt.ylabel('Normalized Value')
plt.xticks(rotation=45, ha='right')
plt.legend()
plt.grid(True)
plt.tight_layout()
plt.show()

# 4. 괴리감 계산 (최근 2년만 출력)
data['Gap'] = data['StockPrice_Norm'] - data['Sales_Norm']
print("\n분기별 정규화된 괴리감 (StockPrice_Norm - Sales_Norm, 최근 2년):")
print(data[['Quarter', 'Gap']].tail(8))
