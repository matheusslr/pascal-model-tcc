import tensorflow as tf

model = tf.keras.Sequential()
model.add(tf.keras.Input(shape=(16,8)))
model.add(tf.keras.layers.LSTM(2, activation="relu", dropout=0.2))
model.add(tf.keras.layers.Dense(8))

model.summary()
