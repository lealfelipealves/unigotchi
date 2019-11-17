<template>
  <div :class="'avatar ' + styleUnigotchi"></div>
</template>

<script>

export default {
  name: 'Avatar',
  props: {
    unigotchi: Object,
  },
  data() {
    return {
      styleUnigotchi: 'alegre-3',
    };
  },
  watch: {
    unigotchi(newVal) {
      if (newVal.vida.value < 1) {
        this.styleUnigotchi = 'rip';
      }
    },
  },
};
</script>

<!-- Add "scoped" attribute to limit CSS to this component only -->
<style scoped lang="scss">
.avatar {
  position: absolute;
  width: 240px;
  height: 240px;
  background-size: cover;
}

.triste-1 {
  background: url('../assets/unigotchi_design-03.svg');
}

.triste-2 {
  background: url('../assets/unigotchi_design-02.svg');
}

.triste-3 {
  background: url('../assets/unigotchi_design-01.svg');
}

.serio {
  background: url('../assets/unigotchi_design-04.svg');
}

.alegre-1 {
  background: url('../assets/unigotchi_design-05.svg');
}

.alegre-2 {
  background: url('../assets/unigotchi_design-06.svg');
}

.alegre-3 {
  background: url('../assets/unigotchi_design-07.svg');
}

.dormindo-boca-aberta {
  background: url('../assets/unigotchi_design-08.svg');
}

.dormindo-sorrindo {
  background: url('../assets/unigotchi_design-09.svg');
}

.rip {
  background: url('../assets/unigotchi_design-10.svg');
}
</style>
