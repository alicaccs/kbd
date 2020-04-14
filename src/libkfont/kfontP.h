#ifndef _KFONT_PRIVATE_H_
#define _KFONT_PRIVATE_H_

#include "kfont.h"

/* loadunimap.c */

int appendunicodemap(struct kfont_context *ctx, int fd, FILE *fp,
		unsigned int ct, int utf8)
	__attribute__((nonnull(1)));

/* kdfontop.c */

/*
 * Read kernel font into BUF with room for COUNT 32x32 glyphs.
 * Return 0 on success -1 on failure.
 * Sets number of glyphs in COUNT, glyph size in WIDTH and HEIGHT.
 */
int getfont(struct kfont_context *ctx, int fd, unsigned char *buf,
		unsigned int *count, unsigned int *width, unsigned int *height)
	__attribute__((nonnull(1)));

/*
 * Load kernel font of width WIDTH and pointsize HEIGHT from BUF
 * with length COUNT.
 * Return 0 on success, -1 on failure.
 */
int putfont(struct kfont_context *ctx, int fd, unsigned char *buf,
		unsigned int count, unsigned int width, unsigned int height)
	__attribute__((nonnull(1)));

/*
 * Find the maximum height of nonblank pixels
 * (in the ((WIDTH+7)/8)*32*COUNT bytes of BUF).
 */
unsigned int font_charheight(unsigned char *buf, unsigned int count,
		unsigned int width)
	__attribute__((nonnull(1)));

/* kdmapop.c */

int getscrnmap(struct kfont_context *ctx, int fd, unsigned char *map)
	__attribute__((nonnull(1)));

int loadscrnmap(struct kfont_context *ctx, int fd, unsigned char *map)
	__attribute__((nonnull(1)));

/* psffontop.c */

#define WPSFH_HASTAB 1
#define WPSFH_HASSEQ 2
int writepsffontheader(struct kfont_context *ctx, FILE *ofil,
		unsigned int width, unsigned int height, unsigned int fontlen,
		int *psftype, int flags);

int appendunicode(struct kfont_context *ctx, FILE *fp, unicode uc, int utf8);
int appendseparator(struct kfont_context *ctx, FILE *fp, int seq, int utf8);

#endif /* _KFONT_PRIVATE_H_ */