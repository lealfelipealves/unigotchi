<template>
  <div class="hello">

    <button class='btn-reset' @click="apiResetUnigotchi()">Reset</button>

    <div class='case'>
      <div class='title'>UNIGOTCHI</div>

      <div class='screen'>
        <avatar :unigotchi="unigotchi" />

        <div class="status life">
          <status tipo="life" :valor="unigotchi.vida.value" />
        </div>
        <div class="status eat">
          <status tipo="eat" :valor="unigotchi.fome.value" />
        </div>
        <div class="status fun">
          <status tipo="fun" :valor="unigotchi.diversao.value" />
        </div>
        <div class="status sleep">
          <status tipo="sleep" :valor="unigotchi.sono.value" />
        </div>
      </div>

      <div class='list-buttons'>
        <button class="btn" type="button" title="Diversão" @click="addDiversao()">Diversão</button>
        <button class="btn wrap-1" type="button" title="Fome" @click="addFome()">Fome</button>
        <button class="btn" type="button" title="Sono"  @click="addSono()">Sono</button>
      </div>
    </div>
  </div>
</template>

<script>
import Status from '@/components/Status.vue';
import Avatar from '@/components/Avatar.vue';

export default {
  name: 'HelloWorld',
  components: {
    Avatar,
    Status,
  },
  data() {
    return {
      unigotchi: {
        diversao: {
          value: 5,
        },
        fome: {
          value: 5,
        },
        sono: {
          value: 5,
        },
        vida: {
          value: 5,
        },
      },
    };
  },

  mounted() {
    this.ready();
  },

  methods: {

    apiResetUnigotchi() {
      this.$http.get(`${this.$baseURI}/reset`);
    },

    apiLoadUnigotchi() {
      this.$http.get(`${this.$baseURI}/status`)
        .then((result) => {
          this.unigotchi = result.data;
        });
    },

    ready() {
      this.apiLoadUnigotchi();

      setInterval(() => {
        this.apiLoadUnigotchi();
      }, 1000);
    },

    addDiversao() {
      if (this.unigotchi.diversao.value < 6) {
        this.$http.post(`${this.$baseURI}/diversao`, { value: 5 })
          .then((result) => {
            this.unigotchi.diversao.value = result.data;
          });
      }
    },
    addFome() {
      if (this.unigotchi.fome.value < 6) {
        this.$http.post(`${this.$baseURI}/fome`, { value: 5 })
          .then((result) => {
            this.unigotchi.fome.value = result.data;
          });
      }
    },
    addSono() {
      if (this.unigotchi.sono.value < 6) {
        this.$http.post(`${this.$baseURI}/sono`, { value: 5 })
          .then((result) => {
            this.unigotchi.sono.value = result.data;
          });
      }
    },
  },
};
</script>

<style scoped lang="scss">
@import url('https://fonts.googleapis.com/css?family=Bangers&display=swap');

.case {
  position: relative;
  box-sizing: border-box;
  width:424px;
  height: 525px;
  border-radius: 100%;
  background: url('../assets/case.svg');
  display:flex;
  justify-content: center;
  align-items: center;
  flex-wrap:wrap;
}

.title {
  position: absolute;
  top:75px;
  width:100%;
  font-family: 'Bangers', cursive;
  font-size: 45px;
  letter-spacing: 1px;
  text-shadow: 2px 2px 1px rgba(77, 9, 50, 0.75);
  color: #fff;
}

.screen {
  position: relative;
  width: 240px;
  height: 240px;
  /*background: #a9e4f2;
  border-radius: 10%;
  box-shadow: inset -2px 2px 0 #0076a4;*/

  .status {
    position: absolute;
  }

  .life {
    top:5px;
    left:5px;
  }

  .fun {
    top:5px;
    right:5px;
  }

  .sleep {
    bottom:7px;
    left:7px;
  }

  .eat {
    bottom:7px;
    right:7px;
  }
}

.list-buttons {
  position: absolute;
  bottom: 35px;
  width:100%;
}
.btn-reset {
  position: absolute;
  top: 1rem;
  right: 1rem;
  border: none;
  padding: 5px 10px;
  border-radius: 100px;
  background: linear-gradient(top, white 5%, #f1f1f1 100%);
  box-shadow: 0 2px 2px rgba(0,0,0,0.1);
}

.btn {
  border:0;
  width:45px;
  height:45px;
  background: #F2F742;
  box-sizing: border-box;
  box-shadow: inset -7px -7px 0 rgba(0,0,0,0.2);
  border-radius: 100%;
  font-size: 0px;
  margin-right:15px;

  &:hover {
    box-shadow: inset -7px -7px 0 rgba(0,0,0,0.35);
  }
}
.wrap-1 {
  padding-bottom: 25px !important;
}

</style>
