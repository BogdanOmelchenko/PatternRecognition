import numpy as np
import pandas as pd
import mnist
import doctest
from time import perf_counter
import matplotlib.pyplot as plt


def vyvod(pxk):
    for i in range(pxk.shape[0]):
        image = pxk[i].reshape((28, 28))
        plt.imshow(image, cmap='gray')
        plt.show()

def nachalnye_dannie(pkx, size):
    """
    >>> nachalnye_dannie(np.array([[1,2],[3,4]]), 4)
    array([1. , 1.5])
    """
    return pkx.sum(axis=0) / size

def m_pxk(pkx, pk, train_shape, train_image):
    n, m = train_shape
    pxk = np.zeros((2, m))
    pxk[0] = np.array([(train_image[:, i] * pkx[:, 0]).sum() for i in range(m)]) / (pk[0] * n)
    pxk[1] = np.array([(train_image[:, i] * pkx[:, 1]).sum() for i in range(m)]) / (pk[1] * n)
    return pxk

def p_pkx(pxk, pk, train_shape, train_image):
    pkx_1 = np.array([
        [np.prod((pxk[0] ** train_image[z]) * ((1 - pxk[0]) ** (1 - train_image[z]))) * pk[0],
         np.prod((pxk[1] ** train_image[z]) * ((1 - pxk[1]) ** (1 - train_image[z]))) * pk[1]]
        for z in range(train_shape[0])])
    pkx = np.array([pkx_1[:, 0], pkx_1[:, 1]]) / (pkx_1[:, 0] + pkx_1[:, 1])
    return np.array([[pkx[0][i], pkx[1][i]] for i in range(train_shape[0])])

def em_alg(t, train_shape, train_image):
    pxk = np.empty((2, train_shape[1]))
    pkx_experta = np.random.uniform(low=0.0, high=1, size=(train_shape[0], 2))
    pkx = pkx_experta / pkx_experta.sum(axis=1).reshape(-1, 1)

    for i in range(t):
        ptk = nachalnye_dannie(pkx, train_shape[0])
        pxk = m_pxk(pkx, ptk, train_shape, train_image)
        pkx = p_pkx(pxk, ptk, train_shape, train_image)
    return pxk

if __name__ == '__main__':

    train_images_, train_labels_ = mnist.train_images().reshape(60000, -1), mnist.train_labels()

    data = pd.DataFrame(np.concatenate([train_labels_.reshape(-1, 1), train_images_], axis=1))
    data = data[data.iloc[:, 0].isin([7, 8])].reset_index(drop=True)
    targets, values = data.iloc[:, 0], data.iloc[:, 1:]
    train_images = values.astype("bool").to_numpy()

    nachalo = perf_counter()
    algoritm = em_alg(20, train_images.shape, train_images)
    konets = perf_counter()
    print(konets - nachalo)
    vyvod(algoritm)
    doctest.testmod()
