#ifndef Q_NEGATIVE_ABS_H
#define Q_NEGATIVE_ABS_H

template <typename T>
inline T qnAbs(const T &t) { return t <= 0 ? t : -t; }

#endif // Q_NEGATIVE_ABS_H
