<template>
  <div>
    <ul :class="tipo">
      <li v-for="index in valor" :key="index"></li>
    </ul>
  </div>
</template>

<script>

export default {
  name: 'Status',
  props: ['valor', 'tipo'],

  data() {
    return {

    };
  },
};
</script>

<!-- Add "scoped" attribute to limit CSS to this component only -->
<style scoped lang="scss">

ul {
  display: flex;
  flex-wrap: nowrap;
  list-style: none;
  padding: 0;
  margin: 0;

  li {
    width: 15px;
    height: 15px;
    background-repeat: no-repeat;
    background-size: cover;
  }
}

.life {
  li {
    margin-right:3px;
    background: url('../assets/unigotchi_design-11.svg');
  }
}

.fun {
  li {
    margin-left:3px;
    background: url('../assets/unigotchi_design-14.svg');
  }
}

.sleep {
  li {
    margin-right:3px;
    background: url('../assets/unigotchi_design-13.svg');
  }
}

.eat {
  li {
    margin-left:3px;
    background: url('../assets/unigotchi_design-12.svg');
  }
}
</style>
