import pandas as ps
import matplotlib.pyplot as plt
import numpy as np


with open("Vc_DATA.txt", "r") as f:
    vc = f.readlines()
    f.close()

with open("Vi_DATA.txt", "r") as f:
    vi = f.readlines()
    f.close()

with open("Va1_DATA.txt", "r") as f:
    va1 = f.readlines()
    f.close()

with open("Va2_DATA.txt", "r") as f:
    va2 = f.readlines()
    f.close()

with open("Va3_DATA.txt", "r") as f:
    va3 = f.readlines()
    f.close()

with open("IntersectionPoints.txt", "r") as f:
    points = f.readlines()
    x1, y1 = (points[0].rstrip('\n')).split('   ')
    x2, y2 = (points[1].rstrip('\n')).split('   ')  #Точки пересечений Va с Vc
    x3, y3 = (points[2].rstrip('\n')).split('   ')

    x4, y4 = (points[3].rstrip('\n')).split('   ')
    x5, y5 = (points[4].rstrip('\n')).split('   ')  #Точки пересечений Va с Vi
    x6, y6 = (points[5].rstrip('\n')).split('   ')
    f.close()


vc_x = []
vi_x = []
va1_x = []
va2_x = []
va3_x = []
data_list_vc = []
data_list_vi = []
data_list_va1 = []
data_list_va2 = []
data_list_va3 = []
for i in vc:
    tmp = (i.rstrip('\n')).split('   ')
    vc_x.append(int(tmp[0]))
    data_list_vc.append(float(tmp[1]))

for i in vi:
    tmp = (i.rstrip('\n')).split('   ')
    vi_x.append(int(tmp[0]))
    data_list_vi.append(float(tmp[1]))

for i in va1:
    tmp = (i.rstrip('\n')).split('   ')
    va1_x.append(int(tmp[0]))
    data_list_va1.append(float(tmp[1]))

for i in va2:
    tmp = (i.rstrip('\n')).split('   ')
    va2_x.append(int(tmp[0]))
    data_list_va2.append(float(tmp[1]))

for i in va3:
    tmp = (i.rstrip('\n')).split('   ')
    va3_x.append(int(tmp[0]))
    data_list_va3.append(float(tmp[1]))


plt.style.use("ggplot")   
figure, ax1 = plt.subplots()

result_array_vc = np.asarray(data_list_vc).T
result_array_vi = np.asarray(data_list_vi).T
result_array_va1 = np.asarray(data_list_va1).T
result_array_va2 = np.asarray(data_list_va2).T
result_array_va3 = np.asarray(data_list_va3).T
ax1.plot(vc_x, result_array_vc, color="red", alpha=0.3, label="Vc", marker="s", markerfacecolor="black", markersize=1)
ax1.plot(vi_x, result_array_vi, color="blue", alpha=0.3, label="Vi", marker="s", markerfacecolor="black", markersize=1)
ax1.plot(va1_x, result_array_va1, color="lime", alpha=0.3, label="Va(Hp=500km)", marker="s", markerfacecolor="black", markersize=1)
ax1.plot(va2_x, result_array_va2, color="yellow", alpha=0.3, label="Va(Hp=5500km)", marker="s", markerfacecolor="black", markersize=1)
ax1.plot(va3_x, result_array_va3, color="violet", alpha=0.3, label="Va(Hp=18000km)", marker="s", markerfacecolor="black", markersize=1)

ax1.plot(float(x1), float(y1), color="black", alpha=1, marker="s", markerfacecolor="black", markersize=1)
ax1.plot(float(x2), float(y2), color="black", alpha=1, marker="s", markerfacecolor="black", markersize=1)
ax1.plot(float(x3), float(y3), color="black", alpha=1, marker="s", markerfacecolor="black", markersize=1)

ax1.plot(float(x4), float(y4), color="black", alpha=1, marker="s", markerfacecolor="black", markersize=1)
ax1.plot(float(x5), float(y5), color="black", alpha=1, marker="s", markerfacecolor="black", markersize=1)
ax1.plot(float(x6), float(y6), color="black", alpha=1, marker="s", markerfacecolor="black", markersize=1)

ax1.legend(loc="upper right")

ax1.set_xlabel("Height above the ground km")
ax1.set_ylabel("Va(Ha/Hp), Vc(Hc), Vi(H/i) km/sec")
plt.show()
